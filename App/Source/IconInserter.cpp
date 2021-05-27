#include "pch.h"
#include "IconInserter.h"

IconInserter::IconInserter(Texture& texture,
						   IconCodex& iconCodex) :
	m_Sprite{texture.GetData()},
    m_SelectedIcon{nullptr},
    m_IconCodex{iconCodex}
{
	const auto textureSize = static_cast<sf::Vector2f>(m_Sprite.getTexture()->getSize());
	m_Sprite.setOrigin(textureSize * 0.5f);
	m_Sprite.setScale(100.0f / textureSize.x, 100.0f / textureSize.y);
	m_Sprite.setRotation(180);
	m_Sprite.setPosition(-1000.0f,
                     -1000.0f);
}

void IconInserter::InsertIcon()
{
	m_SelectedIcon = m_IconCodex.ShowIcon();

	if (m_SelectedIcon == nullptr)
	{
		return;
	}

	m_Sprite.setPosition(m_SelectedIcon->GetSprite().getPosition().x + 10.0f,
                         m_SelectedIcon->GetSprite().getPosition().y - 200.0f);
}

void IconInserter::Draw(sf::RenderWindow& window) const
{
	window.draw(m_Sprite);
}
