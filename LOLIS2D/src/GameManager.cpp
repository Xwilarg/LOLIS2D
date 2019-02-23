#include <SFML/Window/Event.hpp>
#include "GameManager.hpp"

namespace LOLIS2D
{
	GameManager::GameManager(int xSize, int ySize, const std::string &title) noexcept
		: _window(sf::VideoMode(xSize, ySize), title), _scenes(), _currScene(nullptr)
	{ }

	void GameManager::AddScene(std::string &&name) noexcept
	{
		_scenes.emplace_back(std::move(name));
	}

	void GameManager::AddScene(Scene &&scene) noexcept
	{
		_scenes.push_back(std::move(scene));
	}

	bool GameManager::LoadScene(const std::string &name) noexcept
	{
		_currScene = &*std::find_if(_scenes.begin(), _scenes.end(),
			[&name](const Scene &scene) { return (scene.CompareName(name)); });
	}

	void GameManager::Start()
	{
		while (_window.isOpen())
		{
			sf::Event event;
			while (_window.pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
					_window.close();
			}
			_window.clear();
			if (_currScene != nullptr)
				_currScene->Update();
			_window.display();
		}
	}
}