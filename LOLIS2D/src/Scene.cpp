#include <algorithm>
#include "Scene.hpp"

namespace LOLIS2D
{
	Scene::Scene(std::string && name) noexcept
		: _name(std::move(name))
	{ }

	void Scene::Update(sf::RenderWindow &win)
	{
		if (!_toAdd.empty())
		{
			_allGameObjects.reserve(_allGameObjects.size() + _toAdd.size());
			std::move(_toAdd.begin(), _toAdd.end(), std::back_inserter(_allGameObjects));
			_toAdd.clear();
		}
		for (GameObject &go : _allGameObjects)
			go.Update(win);
		for (GameObject &go : _toRemove)
			_allGameObjects.erase(std::find(_allGameObjects.begin(), _allGameObjects.end(), go));
		_toRemove.clear();
	}

	bool Scene::CompareName(const std::string &name) const noexcept
	{
		return (name == _name);
	}

	void Scene::AddGameObject(GameObject &&go) noexcept
	{
		_toAdd.push_back(std::move(go));
	}

	void Scene::RemoveGameObject(GameObject &&go) noexcept
	{
		_toRemove.push_back(std::move(go));
	}
}