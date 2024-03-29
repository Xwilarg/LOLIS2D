#include <SFML/Window/Event.hpp>
#include "GameManager.hpp"
#include "AScript.hpp"
#include "Time.hpp"
#include "Input.hpp"

namespace LOLIS2D
{
	GameManager::GameManager(int xSize, int ySize, const std::string &title) noexcept
		: _window(sf::VideoMode(xSize, ySize), title), _scenes(), _refDelta(), _currScene(nullptr)
	{ }

	void GameManager::AddScene(std::string &&name) noexcept
	{
		_scenes.emplace_back(std::move(name));
		if (_currScene == nullptr)
			_currScene = &_scenes[0];
	}

	void GameManager::AddScene(Scene &&scene) noexcept
	{
		_scenes.push_back(std::move(scene));
		if (_currScene == nullptr)
			_currScene = &_scenes[0];
	}

	void GameManager::LoadScene(const std::string &name) noexcept
	{
		Scene *s = &*std::find_if(_scenes.begin(), _scenes.end(),
			[&name](const Scene &scene) { return (scene.CompareName(name)); });
		bool isSameScene = s == _currScene;
		_currScene = s;
		if (!isSameScene)
			_currScene->Start();
	}

	void GameManager::Start()
	{
		if (_currScene == nullptr)
			throw std::logic_error("No scene was loaded");
		_refDelta = std::chrono::high_resolution_clock::now();
		_currScene->Start();
		while (_window.isOpen())
		{
			sf::Event event;
			while (_window.pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
					_window.close();
				else if (event.type == sf::Event::KeyPressed)
					Input::PressKey(event.key.code);
				else if (event.type == sf::Event::KeyReleased)
					Input::ReleaseKey(event.key.code);
			}
			_window.clear();
			Time::deltaTime = std::chrono::duration_cast<std::chrono::duration<float>>(std::chrono::high_resolution_clock::now() - _refDelta).count();
			_refDelta = std::chrono::high_resolution_clock::now();
			_currScene->Update(_window);
			_window.display();
		}
	}
}