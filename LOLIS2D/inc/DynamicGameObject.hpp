#pragma once

# include "GameObject.hpp"

namespace LOLIS2D
{
	class Scene;

	class DynamicGameObject : public GameObject
	{
	public:
		DynamicGameObject(std::string &&name, Transform &&transform = Transform()) noexcept;
		void Update(const Scene &scene, sf::RenderWindow &win) override;
		void AddForce(const sf::Vector2f &force) noexcept;
		void SetVelocity(sf::Vector2f &&vel) noexcept;
		void SetLinearDrag(float value) noexcept;

	private:
		// Does the new position of a game object collide with anything on the scene
		[[nodiscard]] bool DoesCollide(const Scene &scene, sf::Vector2f vectorAdd) const noexcept;
		float _linearDrag;
		sf::Vector2f _velocity;
	};
}