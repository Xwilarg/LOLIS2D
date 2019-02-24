#include "AScript.hpp"
#include "GameObject.hpp"

namespace LOLIS2D
{
	GameObject::GameObject(std::string &&name, Transform &&transform) noexcept
		: _name(std::move(name)), _transform(std::move(transform)), _renderer(nullptr),
		_scripts(), _toAdd(), _id(id++)
	{ }

	GameObject::GameObject(const GameObject &go) noexcept
		: _name(go._name), _transform(go._transform), _renderer((go._renderer != nullptr) ? (go._renderer->Clone()) : (nullptr)),
		_scripts(), _toAdd(), _id(go._id)
	{
		for (const std::unique_ptr<AScript> &script : go._scripts)
			_scripts.push_back(script->Clone());
		for (const std::unique_ptr<AScript> &script : go._toAdd)
			_toAdd.push_back(script->Clone());
	}

	GameObject::GameObject(GameObject &&go) noexcept
		: _name(std::move(go._name)), _transform(std::move(go._transform)), _renderer(std::move(go._renderer)),
		_scripts(std::move(go._scripts)), _toAdd(std::move(go._toAdd)), _id(std::move(go._id))
	{ }

	GameObject &GameObject::operator=(const GameObject &go) noexcept
	{
		_name = go._name;
		_transform = go._transform;
		for (const std::unique_ptr<AScript> &script : go._scripts)
			_scripts.push_back(script->Clone());
		for (const std::unique_ptr<AScript> &script : go._toAdd)
			_toAdd.push_back(script->Clone());
		_renderer = (go._renderer != nullptr) ? (go._renderer->Clone()) : (nullptr);
		_id = go._id;
		return (*this);
	}

	GameObject &GameObject::operator=(GameObject &&go) noexcept
	{
		_name = std::move(go._name);
		_transform = std::move(go._transform);
		_renderer = std::move(go._renderer);
		_scripts = std::move(go._scripts);
		_toAdd = std::move(go._toAdd);
		_id = std::move(go._id);
		return (*this);
	}

	bool GameObject::operator==(const GameObject &go) const noexcept
	{
		return (_id == go._id);
	}

	void GameObject::Update(sf::RenderWindow &win)
	{
		if (!_toAdd.empty())
		{
			_scripts.reserve(_scripts.size() + _toAdd.size());
			std::move(_toAdd.begin(), _toAdd.end(), std::back_inserter(_scripts));
			_toAdd.clear();
		}
		if (_renderer != nullptr)
			_renderer->Draw(win);
	}

	void GameObject::Move(sf::Vector2f &&pos) noexcept
	{
		if (_renderer != nullptr)
			_renderer->Move(pos);
		_transform.Move(std::move(pos));
	}

	int GameObject::id = 0;
}