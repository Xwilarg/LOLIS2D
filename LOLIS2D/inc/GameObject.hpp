#pragma once

# include <string>
# include "Transform.hpp"

namespace LOLIS2D
{
	class GameObject
	{
	public:
		GameObject(std::string &&name, Transform &&transform = Transform()) noexcept;
		virtual ~GameObject() noexcept = default;
		[[nodiscard]] bool operator==(const GameObject &go) const noexcept;
		void Update();

	private:
		std::string _name;
		Transform _transform;
		int _id;
		static int id;
	};
}