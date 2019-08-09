#include "AScript.hpp"
#include "Scene.hpp"

namespace LOLIS2D
{
	DynamicGameObject::DynamicGameObject(std::string &&name, Transform &&transform) noexcept
		: GameObject(std::move(name), std::move(transform)), _linearDrag(1.1f), _velocity(sf::Vector2f(0.f, 0.f))
	{ }

	void DynamicGameObject::Update(const Scene &scene, sf::RenderWindow &win)
	{
		GameObject::Update(scene, win);
		if (!DoesCollide(scene, _velocity))
		{
			Move(_velocity);
		}
		_velocity /= _linearDrag;
	}

	void DynamicGameObject::AddForce(const sf::Vector2f &force) noexcept
	{
		_velocity += force;
	}

	void DynamicGameObject::SetVelocity(sf::Vector2f &&vel) noexcept
	{
		_velocity = std::move(vel);
	}

	bool DynamicGameObject::DoesCollide(const Scene &scene, sf::Vector2f vectorAdd) const noexcept
	{
		//return scene.AnyGameObject([](const GameObject &go) { return false; });
	}

	void DynamicGameObject::SetLinearDrag(float value) noexcept
	{
		_linearDrag = value;
	}
}