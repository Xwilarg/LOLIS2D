#pragma once

# include <string>
# include "Transform.hpp"
# include "IRenderer.hpp"

namespace LOLIS2D
{
	class AScript;

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
		void Move(sf::Vector2f &&pos) noexcept;
		template<class T, typename... Args>
		void AddRenderer(Args&&... params)
		{
			_renderer = std::make_unique<T>(std::forward<Args>(params)...);
		}
		template<class T>
		void AddScript()
		{
			_toAdd.emplace_back<T>(*this);
		}

	private:
		std::string _name;
		Transform _transform;
		std::unique_ptr<IRenderer> _renderer;
		std::vector<std::unique_ptr<AScript>> _scripts;
		std::vector<std::unique_ptr<AScript>> _toAdd;
		int _id;
		static int id;
	};
}