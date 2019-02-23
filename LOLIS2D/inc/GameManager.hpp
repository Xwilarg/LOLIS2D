#pragma once

# include <SFML/Graphics/RenderWindow.hpp>
# include "Scene.hpp"

namespace LOLIS2D
{
	class GameManager final
	{
	public:
		GameManager(int xSize, int ySize, const std::string &title) noexcept;
		void AddScene(std::string &&name) noexcept;
		void AddScene(Scene &&scene) noexcept;
		bool LoadScene(const std::string &name) noexcept;
		void Start();

	private:
		sf::RenderWindow _window;
		std::vector<Scene> _scenes;
		Scene *_currScene;
	};
}