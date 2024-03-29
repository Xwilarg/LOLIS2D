#pragma once

# include <string>
# include "Transform.hpp"
# include "IRenderer.hpp"
# include "ICollider.hpp"

namespace LOLIS2D
{
	class AScript;
	class DynamicGameObject;
	class Scene;

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
		void Start();
		virtual void Update(const Scene &scene, sf::RenderWindow &win);
		void Move(sf::Vector2f &&pos) noexcept;
		void Move(const sf::Vector2f &pos) noexcept;
		DynamicGameObject *CastToDynamic() noexcept;
		template<class T, typename... Args>
		void AddRenderer(Args&&... params) noexcept
		{
			_renderer = std::make_unique<T>(std::forward<Args>(params)...);
			_renderer->SetPosition(_transform.GetPosition());
		}
		template<class T, typename... Args>
		void AddCollider(Args&&... params) noexcept
		{
			_collider = std::make_unique<T>(std::forward<Args>(*this, params)...);
		}
		template<class T>
		void AddScript() noexcept
		{
			_toAdd.push_back(std::make_unique<T>(this));
		}

	private:
		void PreAction() noexcept; // To call before Start and Update
		void InternalMove() noexcept; // Update Renderer when transform is moved
		void UpdateScripts() noexcept;
		std::string _name;
		Transform _transform;
		std::unique_ptr<IRenderer> _renderer;
		std::unique_ptr<ICollider> _collider;
		std::vector<std::unique_ptr<AScript>> _scripts;
		std::vector<std::unique_ptr<AScript>> _toAdd;
		int _id;
		static int id;
	};
}