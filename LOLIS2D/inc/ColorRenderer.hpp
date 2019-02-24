#pragma once

# include <SFML/Graphics/Color.hpp>
# include <SFML/Graphics/RectangleShape.hpp>
# include "IRenderer.hpp"

namespace LOLIS2D
{
	class ColorRenderer final : public IRenderer
	{
	public:
		ColorRenderer(const sf::Color &color, const sf::Vector2f &pos) noexcept;
		void Draw(sf::RenderWindow &win) const noexcept override;
		void Move(const sf::Vector2f &pos) noexcept override;
		std::unique_ptr<IRenderer> Clone() const noexcept;

	private:
		sf::RectangleShape _rect;
	};
}