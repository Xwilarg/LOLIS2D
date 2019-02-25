#include "AScript.hpp"
#include "DynamicGameObject.hpp"

namespace LOLIS2D
{
	DynamicGameObject::DynamicGameObject(std::string &&name, Transform &&transform) noexcept
		: GameObject(std::move(name), std::move(transform)), _linearDrag(1.1f), _velocity(sf::Vector2f(0.f, 0.f))
	{ }

	void DynamicGameObject::Update(sf::RenderWindow &win)
	{
		GameObject::Update(win);
		Move(_velocity);
		_velocity /= _linearDrag;
	}

	void DynamicGameObject::AddForce(const sf::Vector2f &force) noexcept
	{
		_velocity += force;
	}
}