#pragma once

# include "GameObject.hpp"

namespace LOLIS2D
{
	class DynamicGameObject : public GameObject
	{
	public:
		DynamicGameObject(std::string &&name, Transform &&transform = Transform()) noexcept;
		void Update(sf::RenderWindow &win) override;
		void AddForce(const sf::Vector2f &force) noexcept;

	private:
		float _linearDrag;
		sf::Vector2f _velocity;
	};
}