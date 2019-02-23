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

	private:
		sf::RectangleShape _rect;
	};
}