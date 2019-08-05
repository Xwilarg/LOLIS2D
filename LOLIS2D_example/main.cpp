#include "GameManager.hpp"
#include "DynamicGameObject.hpp"
#include "ColorRenderer.hpp"
#include "AScript.hpp"
#include "Time.hpp"
#include "Input.hpp"

class PlayerController final : public LOLIS2D::AScript
{
	CUSTOM_SCRIPT(PlayerController) // Every custom script must implement this macro

private:
	const float speed = 200.f;
	LOLIS2D::DynamicGameObject *dynamicGo;

public:
	void Start() override
	{
		dynamicGo = _gameObject->CastToDynamic();
	}

	void Update() override
	{
		float hor = 0.f, ver = 0.f;
		if (LOLIS2D::Input::IsPressed(sf::Keyboard::S))
			ver = speed;
		if (LOLIS2D::Input::IsPressed(sf::Keyboard::W))
			ver = -speed;
		if (LOLIS2D::Input::IsPressed(sf::Keyboard::A))
			hor = -speed;
		if (LOLIS2D::Input::IsPressed(sf::Keyboard::D))
			hor = speed;
		dynamicGo->SetVelocity(sf::Vector2f(hor, ver) * LOLIS2D::Time::deltaTime);
	}
};

int main()
{
	LOLIS2D::GameManager gm(500, 200, "LOLIS2D Test");
	LOLIS2D::Scene mainScene("Main");
	LOLIS2D::DynamicGameObject player("Player");
	player.AddRenderer<LOLIS2D::ColorRenderer>(sf::Color::Red);
	player.AddScript<PlayerController>();
	mainScene.AddGameObject(std::move(player));
	gm.AddScene(std::move(mainScene)); // First added scene is loaded by default
	gm.Start();
	return (0);
}