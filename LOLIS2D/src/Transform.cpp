#include "Transform.hpp"

namespace LOLIS2D
{
	Transform::Transform() noexcept
		: _position(sf::Vector2f(0.f, 0.f)), _rotation(0.f)
	{ }
}