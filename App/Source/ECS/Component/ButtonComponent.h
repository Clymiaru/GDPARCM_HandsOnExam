#pragma once
#include <functional>

#include "TransformComponent.h"

class ButtonComponent final : public AComponent
{
public:
	ButtonComponent(Entity& entity,
					TransformComponent& transform,
					const sf::Vector2f& buttonSize,
					std::function<void()> onPressEvent);
	~ButtonComponent() override;
	MAKE_COMPONENT(ButtonComponent)

	sf::FloatRect& GetButtonRect() const;
	void Execute() const;
private:
	sf::FloatRect* m_ButtonRect;
	std::function<void()> m_OnPress;
};
