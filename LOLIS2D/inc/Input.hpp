#pragma once

# include <SFML/Window/Keyboard.hpp>
# include <vector>

namespace LOLIS2D
{
	class Input final
	{
	public:
		static void PressKey(sf::Keyboard::Key key) noexcept;
		static void ReleaseKey(sf::Keyboard::Key key) noexcept;
		static bool IsPressed(sf::Keyboard::Key key) noexcept;

	private:
		static std::vector<sf::Keyboard::Key> _pressed;
	};
}