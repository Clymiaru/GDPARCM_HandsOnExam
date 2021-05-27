#include "pch.h"
#include "Icon.h"

Icon::Icon(Texture& texture,
		   const sf::Vector2i& position) :
	m_Position{position},
	m_SpriteSize{texture.GetData().getSize()},
	m_Sprite{texture.GetData()}
{
	UpdateSpritePosition();
}

Icon::~Icon()
{
}

sf::Sprite& Icon::GetSprite()
{
	return m_Sprite;
}

void Icon::SetSize(const sf::Vector2f& spriteSize)
{
	m_SpriteSize = spriteSize;

	const sf::Vector2f textureSize =
	{
		static_cast<float>(m_Sprite.getTexture()->getSize().x),
        static_cast<float>(m_Sprite.getTexture()->getSize().y),
    };

	m_Sprite.setOrigin(m_SpriteSize.x / 2.0f, m_SpriteSize.y / 2.0f);

	m_Sprite.setScale(
        {
            m_SpriteSize.x / textureSize.x,
            m_SpriteSize.y / textureSize.y
        });
}

void Icon::SetPosition(const sf::Vector2i& position,
                       const sf::Vector2f& worldOffset,
                       const float spacing)
{
	m_Position = position;
	UpdateSpritePosition(worldOffset, spacing);
}

void Icon::UpdateSpritePosition(const sf::Vector2f& worldOffset,
								const float spacing)
{
	m_Sprite.setOrigin(m_SpriteSize.x / 2.0f, m_SpriteSize.y / 2.0f);
	
	m_Sprite.setPosition(
        {
            worldOffset.x + (m_SpriteSize.x  + spacing) * m_Position.x,
        	worldOffset.y + (m_SpriteSize.y  + spacing) * m_Position.y
        });
}
