#include <SFML/Window/Event.hpp>
#include "GameManager.hpp"

namespace LOLIS2D
{
	GameManager::GameManager(int xSize, int ySize, const std::string &title) noexcept
		: _window(sf::VideoMode(xSize, ySize), title)
	{ }

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
			_window.display();
		}
	}
}