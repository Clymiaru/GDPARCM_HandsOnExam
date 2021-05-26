#include "pch.h"
#include "SpriteRendererComponent.h" 


#include "ECS/Entity.h"

SpriteRendererComponent::SpriteRendererComponent(Entity& owner,
												 Texture& texture,
												 TransformComponent& transformComponent) :
	AComponent{owner},
	m_Sprite{texture.GetData()},
	m_Transform{transformComponent},
	m_Texture{texture}
{
	const auto textureSize = m_Sprite.getTexture()->getSize();
	m_Sprite.setOrigin(textureSize.x / 2.0f, textureSize.y / 2.0f);
}

SpriteRendererComponent::~SpriteRendererComponent()
{
}

void SpriteRendererComponent::SetTextureRect(const sf::IntRect& textureRect)
{
	m_Sprite.setTextureRect(textureRect);
	m_Sprite.setOrigin(textureRect.width / 2.0f, textureRect.height / 2.0f);
}

void SpriteRendererComponent::SetOrigin(const sf::Vector2f origin)
{
	m_Sprite.setOrigin(origin);
}

void SpriteRendererComponent::SetAlpha(float alpha)
{
	const auto color = m_Sprite.getColor();
	m_Sprite.setColor(sf::Color(color.r, color.g, color.b, 255 * alpha));
}

const sf::Sprite& SpriteRendererComponent::GetSprite() const
{
	return m_Sprite;
}

const sf::Transform& SpriteRendererComponent::GetTransform() const
{
	return m_Transform.GetRawTransform();
}
