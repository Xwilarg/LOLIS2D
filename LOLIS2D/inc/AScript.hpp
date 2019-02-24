#pragma once

# include "GameObject.hpp"

// Every custom script must implement the following macro (Type if the name of the class)
#define CUSTOM_SCRIPT(TYPE) \
	public: \
	TYPE(LOLIS2D::GameObject &go) : LOLIS2D::AScript(go) { } \
	std::unique_ptr<AScript> Clone() const noexcept override \
	{ return (std::make_unique<TYPE>(*this)); } \
	private:

namespace LOLIS2D
{
	class AScript
	{
	public:
		AScript(GameObject &gameObject) noexcept;
		virtual ~AScript() noexcept = default;
		virtual std::unique_ptr<AScript> Clone() const noexcept = 0;
		virtual void Start();
		virtual void Update();

	protected:
		GameObject &_gameObject;
	};
}