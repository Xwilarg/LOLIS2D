#include <utility>
#include "Transform.hpp"

namespace LOLIS2D
{
	Transform::Transform() noexcept
		: _position(sf::Vector2f(0.f, 0.f)), _rotation(0.f)
	{ }

	void Transform::Move(const sf::Vector2f &pos) noexcept
	{
		_position += pos;
	}

	const sf::Vector2f &Transform::GetPosition() const noexcept
	{
		return (_position);
	}
}