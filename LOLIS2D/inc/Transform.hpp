#pragma once

#include <SFML/System/Vector2.hpp>

namespace LOLIS2D
{
	class Transform final
	{
	public:
		Transform() noexcept;
		void Move(const sf::Vector2f &pos) noexcept;
		const sf::Vector2f &GetPosition() const noexcept;

	private:
		sf::Vector2f _position;
		float _rotation;
	};
}