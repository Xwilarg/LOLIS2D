#include "GameObject.hpp"

namespace LOLIS2D
{
	GameObject::GameObject(std::string &&name, Transform &&transform) noexcept
		: _name(std::move(name)), _transform(std::move(transform)), _renderer(nullptr), _id(id++)
	{ }

	GameObject::GameObject(const GameObject &go) noexcept
		: _name(go._name), _transform(go._transform), _renderer((go._renderer != nullptr) ? (go._renderer->Clone()) : (nullptr)), _id(go._id)
	{ }

	GameObject::GameObject(GameObject &&go) noexcept
		: _name(std::move(go._name)), _transform(std::move(go._transform)), _renderer(std::move(go._renderer)), _id(std::move(go._id))
	{ }

	GameObject &GameObject::operator=(const GameObject &go) noexcept
	{
		_name = go._name;
		_transform = go._transform;
		_renderer = (go._renderer != nullptr) ? (go._renderer->Clone()) : (nullptr);
		_id = go._id;
		return (*this);
	}

	GameObject &GameObject::operator=(GameObject &&go) noexcept
	{
		_name = std::move(go._name);
		_transform = std::move(go._transform);
		_renderer = std::move(go._renderer);
		_id = std::move(go._id);
		return (*this);
	}

	bool GameObject::operator==(const GameObject &go) const noexcept
	{
		return (_id == go._id);
	}

	void GameObject::Update(sf::RenderWindow &win)
	{
		if (_renderer != nullptr)
			_renderer->Draw(win);
	}

	int GameObject::id = 0;
}