#pragma once

#include <SFML/System/Vector2.hpp>

namespace LOLIS2D
{
	class Transform final
	{
	public:
		Transform() noexcept;

	private:
		sf::Vector2f _position;
		float _rotation;
	};
}