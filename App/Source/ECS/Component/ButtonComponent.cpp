#include "pch.h"
#include "ButtonComponent.h"

ButtonComponent::ButtonComponent(Entity& entity,
								 TransformComponent& transform,
								 const sf::Vector2f& buttonSize,
								 std::function<void()> onPressEvent) :
	AComponent{entity},
	m_ButtonRect{new sf::FloatRect(transform.GetPosition().x - buttonSize.x / 2.0f,
							   transform.GetPosition().y - buttonSize.y / 2.0f,
							   transform.GetPosition().x + buttonSize.x / 2.0f,
							   transform.GetPosition().y + buttonSize.y / 2.0f)},
	m_OnPress{onPressEvent}
{
}

ButtonComponent::~ButtonComponent()
{
}

sf::FloatRect& ButtonComponent::GetButtonRect() const
{
	return *m_ButtonRect;
}

void ButtonComponent::Execute() const
{
	m_OnPress();
}

