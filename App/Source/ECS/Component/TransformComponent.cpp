#include "pch.h"
#include "TransformComponent.h"

TransformComponent::TransformComponent(Entity& owner,
									   sf::Transformable initialTransform) :
	AComponent{owner},
	m_Transform{initialTransform}
{
}

TransformComponent::~TransformComponent()
{
}

void TransformComponent::SetPosition(const sf::Vector2f& position)
{
	m_Transform.setPosition(position);
}

const sf::Vector2f& TransformComponent::GetPosition() const
{
	return m_Transform.getPosition();
}

void TransformComponent::Move(const sf::Vector2f& moveVector)
{
	m_Transform.move(moveVector);
}

void TransformComponent::SetScale(const sf::Vector2f& scale)
{
	m_Transform.setScale(scale);
}

const sf::Vector2f& TransformComponent::GetScale() const
{
	return m_Transform.getScale();
}

void TransformComponent::Scale(const sf::Vector2f& scaleVector)
{
	m_Transform.scale(scaleVector);
}

void TransformComponent::Rotate(const float angleInDegrees)
{
	m_Transform.rotate(angleInDegrees);
}

void TransformComponent::SetRotation(const float rotation)
{
	m_Transform.setRotation(rotation);
}

float TransformComponent::GetRotation() const
{
	return m_Transform.getRotation();
}

const sf::Transform& TransformComponent::GetRawTransform() const
{
	return m_Transform.getTransform();
}
