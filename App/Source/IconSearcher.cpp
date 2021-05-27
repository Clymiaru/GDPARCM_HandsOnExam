#include "pch.h"
#include "IconSearcher.h"

IconSearcher::IconSearcher(Texture& texture,
						   IconCodex& iconCodex) :
	m_Sprite{texture.GetData()},
	m_SelectedIconID{0},
	m_SelectedIcon{nullptr},
	m_IconCodex{iconCodex}
{
	const auto textureSize = static_cast<sf::Vector2f>(m_Sprite.getTexture()->getSize());
	m_Sprite.setOrigin(textureSize * 0.5f);
	m_Sprite.setScale(100.0f / textureSize.x, 100.0f / textureSize.y);
}

void IconSearcher::Draw(sf::RenderWindow& window) const
{
	window.draw(m_Sprite);
}

void IconSearcher::SelectNextIcon()
{
	do
	{
		m_SelectedIcon = m_IconCodex.SelectIcon(m_SelectedIconID);
		m_SelectedIconID = (m_SelectedIconID + 1) % m_IconCodex.GetActiveIconsCount();
	} while (m_SelectedIcon == nullptr);

	m_Sprite.setPosition(m_SelectedIcon->GetSprite().getPosition().x + 10.0f,
                        m_SelectedIcon->GetSprite().getPosition().y + 100.0f);
}