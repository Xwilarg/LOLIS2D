#pragma once

# include <string>
# include <vector>
# include "GameObject.hpp"

namespace LOLIS2D
{
	class Scene final
	{
	public:
		Scene(std::string &&name) noexcept;
		void Update(sf::RenderWindow &win);
		[[nodiscard]] bool CompareName(const std::string &name) const noexcept;
		void AddGameObject(GameObject &&go) noexcept;
		void RemoveGameObject(GameObject &&go) noexcept;

	private:
		std::vector<GameObject> _allGameObjects;
		std::vector<GameObject> _toAdd; // Objects to add are stored here before being added at the start of the Update loop
		std::vector<GameObject> _toRemove;
		std::string _name;
	};
}