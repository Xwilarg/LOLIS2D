#include <algorithm>
#include "Scene.hpp"
#include "AScript.hpp"

namespace LOLIS2D
{
	Scene::Scene(std::string && name) noexcept
		: _name(std::move(name))
	{ }

	void Scene::Start()
	{
		AddVectors(_toAdd, _allGameObjects);
		AddVectors(_toAddDynamic, _allDynamicGameObjects);
		for (GameObject &go : _allGameObjects)
			go.Start();
		for (DynamicGameObject &go : _allDynamicGameObjects)
			go.Start();
		RemoveVectors(_toRemove, _allGameObjects);
		RemoveVectors(_toRemoveDynamic, _allDynamicGameObjects);
	}

	void Scene::Update(sf::RenderWindow &win)
	{
		AddVectors(_toAdd, _allGameObjects);
		AddVectors(_toAddDynamic, _allDynamicGameObjects);
		for (GameObject &go : _allGameObjects)
			go.Update(*this, win);
		for (DynamicGameObject &go : _allDynamicGameObjects)
			go.Update(*this, win);
		RemoveVectors(_toRemove, _allGameObjects);
		RemoveVectors(_toRemoveDynamic, _allDynamicGameObjects);
	}

	bool Scene::CompareName(const std::string &name) const noexcept
	{
		return (name == _name);
	}

	void Scene::AddGameObject(DynamicGameObject &&go) noexcept
	{
		_toAddDynamic.push_back(std::move(go));
	}

	void Scene::RemoveGameObject(DynamicGameObject &&go) noexcept
	{
		_toRemoveDynamic.push_back(std::move(go));
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