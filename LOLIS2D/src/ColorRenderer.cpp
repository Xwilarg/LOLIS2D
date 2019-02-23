#include <utility>
#include "ColorRenderer.hpp"

namespace LOLIS2D
{
	ColorRenderer::ColorRenderer(const sf::Color &color) noexcept
		: _rect(sf::Vector2f(1.f, 1.f))
	{
		_rect.setFillColor(color);
	}
}