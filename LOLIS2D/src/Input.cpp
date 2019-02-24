#include <algorithm>
#include "Input.hpp"

namespace LOLIS2D
{
	void Input::PressKey(sf::Keyboard::Key key) noexcept
	{
		_pressed.push_back(key);
	}

	void Input::ReleaseKey(sf::Keyboard::Key key) noexcept
	{
		_pressed.erase(std::remove(_pressed.begin(), _pressed.end(), key), _pressed.end());
	}

	bool Input::IsPressed(sf::Keyboard::Key key) noexcept
	{
		return (std::find(_pressed.begin(), _pressed.end(), key) != _pressed.end());
	}

	std::vector<sf::Keyboard::Key> Input::_pressed;
}