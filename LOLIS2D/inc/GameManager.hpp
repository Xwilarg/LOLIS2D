#pragma once

# include <SFML/Graphics/RenderWindow.hpp>

namespace LOLIS2D
{
	class GameManager final
	{
	public:
		GameManager(int xSize, int ySize, const std::string &title) noexcept;
		void Start();

	private:
		sf::RenderWindow _window;
	};
}