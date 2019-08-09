#pragma once

namespace LOLIS2D
{
	class GameObject;

	class ICollider
	{
	public:
		virtual ~ICollider() noexcept = default;
		virtual bool DoesCollide(const ICollider &other) const noexcept = 0;

	protected:
		GameObject &parent;
	};
}