#pragma once

# include <string>
# include <vector>
# include "DynamicGameObject.hpp"

namespace LOLIS2D
{
	class Scene final
	{
	public:
		Scene(std::string &&name) noexcept;
		void Start();
		void Update(sf::RenderWindow &win);
		[[nodiscard]] bool CompareName(const std::string &name) const noexcept;
		void AddGameObject(DynamicGameObject &&go) noexcept;
		void RemoveGameObject(DynamicGameObject &&go) noexcept;
		void AddGameObject(GameObject &&go) noexcept;
		void RemoveGameObject(GameObject &&go) noexcept;

	private:
		// Add / Remove all game object in a list
		// It's templated because it can be applied on GameObject and DynamicGameObject
		template<class T>
		void AddVectors(std::vector<T> &toAdd, std::vector<T> &allGameObjects) noexcept
		{
			if (!toAdd.empty())
			{
				allGameObjects.reserve(allGameObjects.size() + toAdd.size());
				std::move(toAdd.begin(), toAdd.end(), std::back_inserter(allGameObjects));
				toAdd.clear();
			}
		}
		template<class T>
		void RemoveVectors(std::vector<T> &toRemove, std::vector<T> &allGameObjects) noexcept
		{
			for (GameObject &go : toRemove)
				allGameObjects.erase(std::find(allGameObjects.begin(), allGameObjects.end(), go));
			toRemove.clear();
		}
		std::vector<GameObject> _allGameObjects;
		// Objects to add are stored here before being added at the start of the Update loop
		// It's made that way to make sure we don't modify _allGameObjects while the program is interating on it
		// TODO: Maybe I can just improve the performances by iterating from list.length to 0, so I can add things without any problem
		std::vector<GameObject> _toAdd;
		std::vector<GameObject> _toRemove;
		// Dynamic GameObjects are stored separatly so I don't have handle polymorphism
		// (unique_ptr need me to redefine copy/mov ctor/equal-op and it's annoying)
		// (also that allow the user to manipulate GameObject and not unique_ptr)
		std::vector<DynamicGameObject> _allDynamicGameObjects;
		std::vector<DynamicGameObject> _toAddDynamic;
		std::vector<DynamicGameObject> _toRemoveDynamic;
		std::string _name;
	};
}