#include "GameObject.hpp"

namespace LOLIS2D
{
	GameObject::GameObject(std::string &&name, Transform &&transform) noexcept
		: _name(std::move(name)), _transform(std::move(transform)), _id(id++)
	{ }

	bool GameObject::operator==(const GameObject &go) const noexcept
	{
		return (_id == go._id);
	}

	void GameObject::Update()
	{

	}

	int GameObject::id = 0;
}