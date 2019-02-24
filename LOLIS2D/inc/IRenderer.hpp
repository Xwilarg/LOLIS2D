#pragma once

# include <SFML/Graphics/RenderWindow.hpp>

namespace LOLIS2D
{
	class IRenderer
	{
	public:
		virtual ~IRenderer() noexcept = default;
		virtual void Draw(sf::RenderWindow &win) const noexcept = 0;
		virtual void Move(const sf::Vector2f &pos) noexcept = 0; // Called when game object is moved so renderer can be updated
		virtual std::unique_ptr<IRenderer> Clone() noexcept = 0;
	};
}