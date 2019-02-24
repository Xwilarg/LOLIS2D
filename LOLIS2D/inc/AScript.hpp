#pragma once

# include "GameObject.hpp"

namespace LOLIS2D
{
	class AScript
	{
	public:
		AScript(GameObject &gameObject) noexcept;
		virtual ~AScript() noexcept = default;
		virtual std::unique_ptr<AScript> Clone() const noexcept = 0;

	protected:
		GameObject &_gameObject;
	};
}