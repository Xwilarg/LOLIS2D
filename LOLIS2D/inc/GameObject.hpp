#pragma once

# include <string>
# include "Transform.hpp"
# include "IRenderer.hpp"

namespace LOLIS2D
{
	class GameObject
	{
	public:
		GameObject(std::string &&name, Transform &&transform = Transform()) noexcept;
		GameObject(const GameObject &go) noexcept;
		GameObject(GameObject &&go) noexcept;
		virtual ~GameObject() noexcept = default;
		GameObject &operator=(const GameObject &go) noexcept;
		GameObject &operator=(GameObject &&go) noexcept;
		[[nodiscard]] bool operator==(const GameObject &go) const noexcept;
		void Update(sf::RenderWindow &win);
		template <class T, typename... Args>
		void AddRenderer(Args&&... params)
		{
			_renderer = std::make_unique<T>(std::forward<Args>(params)...);
		}

	private:
		std::string _name;
		Transform _transform;
		std::unique_ptr<IRenderer> _renderer;
		int _id;
		static int id;
	};
}