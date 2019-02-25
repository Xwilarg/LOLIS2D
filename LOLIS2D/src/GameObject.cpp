#include "AScript.hpp"
#include "DynamicGameObject.hpp"

namespace LOLIS2D
{
	GameObject::GameObject(std::string &&name, Transform &&transform) noexcept
		: _name(std::move(name)), _transform(std::move(transform)), _renderer(nullptr),
		_scripts(), _toAdd(), _id(id++)
	{ }

	GameObject::GameObject(const GameObject &go) noexcept
		: _name(go._name), _transform(go._transform), _renderer((go._renderer != nullptr) ? (go._renderer->Clone()) : (nullptr)),
		_scripts(), _toAdd(), _id(id++)
	{
		_scripts.clear();
		_toAdd.clear();
		for (const std::unique_ptr<AScript> &script : go._scripts)
			_scripts.push_back(script->Clone());
		for (const std::unique_ptr<AScript> &script : go._toAdd)
			_toAdd.push_back(script->Clone());
		UpdateScripts();
	}

	GameObject::GameObject(GameObject &&go) noexcept
		: _name(std::move(go._name)), _transform(std::move(go._transform)), _renderer(std::move(go._renderer)),
		_scripts(std::move(go._scripts)), _toAdd(std::move(go._toAdd)), _id(std::move(go._id))
	{
		UpdateScripts();
	}

	GameObject &GameObject::operator=(const GameObject &go) noexcept
	{
		_name = go._name;
		_transform = go._transform;
		_scripts.clear();
		_toAdd.clear();
		for (const std::unique_ptr<AScript> &script : go._scripts)
			_scripts.push_back(script->Clone());
		for (const std::unique_ptr<AScript> &script : go._toAdd)
			_toAdd.push_back(script->Clone());
		_renderer = (go._renderer != nullptr) ? (go._renderer->Clone()) : (nullptr);
		_id = id++;
		UpdateScripts();
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
		UpdateScripts();
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
		for (std::unique_ptr<AScript> &script : _scripts)
			script->Update();
		if (_renderer != nullptr)
			_renderer->Draw(win);
	}

	void GameObject::Move(sf::Vector2f &&pos) noexcept
	{
		_transform.Move(std::move(pos));
		InternalMove();
	}

	void GameObject::Move(const sf::Vector2f &pos) noexcept
	{
		_transform.Move(pos);
		InternalMove();
	}

	DynamicGameObject *GameObject::CastToDynamic() noexcept
	{
		return (dynamic_cast<DynamicGameObject *>(this));
	}

	void GameObject::InternalMove() noexcept
	{
		if (_renderer != nullptr)
			_renderer->SetPosition(_transform.GetPosition());
	}

	void GameObject::UpdateScripts() noexcept
	{
		for (std::unique_ptr<AScript> &script : _scripts)
			script->UpdateGameObject(this);
		for (std::unique_ptr<AScript> &script : _toAdd)
			script->UpdateGameObject(this);
	}

	int GameObject::id = 0;
}