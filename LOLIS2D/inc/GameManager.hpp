#pragma once

# include <SFML/Graphics/RenderWindow.hpp>
# include <chrono>
# include "Scene.hpp"

namespace LOLIS2D
{
	class GameManager final
	{
	public:
		GameManager(int xSize, int ySize, const std::string &title) noexcept;
		GameManager(const GameManager& gm) = delete; // Game Manager have no reason of being copied
		void AddScene(std::string &&name) noexcept;
		void AddScene(Scene &&scene) noexcept;
		void LoadScene(const std::string &name) noexcept;
		void Start();

	private:
		sf::RenderWindow _window;
		std::vector<Scene> _scenes;
		std::chrono::high_resolution_clock::time_point _refDelta;
		Scene *_currScene;
	};
}