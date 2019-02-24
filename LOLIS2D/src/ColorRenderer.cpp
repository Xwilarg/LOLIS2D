#include <utility>
#include "ColorRenderer.hpp"

namespace LOLIS2D
{
	ColorRenderer::ColorRenderer(const sf::Color &color, const sf::Vector2f &pos) noexcept
		: _rect(sf::Vector2f(10.f, 10.f))
	{
		_rect.setPosition(pos);
		_rect.setFillColor(color);
	}

	void ColorRenderer::Draw(sf::RenderWindow &win) const noexcept
	{
		win.draw(_rect);
	}

	void ColorRenderer::Move(const sf::Vector2f &pos) noexcept
	{
		_rect.setPosition(pos);
	}

	std::unique_ptr<IRenderer> ColorRenderer::Clone() const noexcept
	{
		return (std::make_unique<ColorRenderer>(*this));
	}
}