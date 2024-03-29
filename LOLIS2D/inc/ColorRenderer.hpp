#pragma once

# include <SFML/Graphics/Color.hpp>
# include <SFML/Graphics/RectangleShape.hpp>
# include "IRenderer.hpp"

namespace LOLIS2D
{
	class ColorRenderer final : public IRenderer
	{
	public:
		ColorRenderer(const sf::Color &color) noexcept;
		void Draw(sf::RenderWindow &win) const noexcept override;
		void SetPosition(const sf::Vector2f &pos) noexcept override;
		std::unique_ptr<IRenderer> Clone() const noexcept;

	private:
		sf::RectangleShape _rect;
	};
}