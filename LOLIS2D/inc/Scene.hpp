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

		template <class T>
		bool AnyGameObject(T &&fct) const noexcept
		{
			for (auto &go : _allGameObjects)
				if (fct(go))
					return true;
			for (auto &go : _allDynamicGameObjects)
				if (fct(go))
					return true;
			return false;
		}

	private:
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
		std::vector<GameObject> _toAdd; // Objects to add are stored here before being added at the start of the Update loop
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