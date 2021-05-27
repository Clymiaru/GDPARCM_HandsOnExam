#include "pch.h"
#include "IconDeleter.h"

#include "Utils/Random.h"

IconDeleter::IconDeleter(Texture& texture,
                         List<Icon*>& iconList) :
	m_Sprite{texture.GetData()},
	m_SelectedIconID{0},
	m_IconList{iconList}
{
	const auto textureSize = static_cast<sf::Vector2f>(m_Sprite.getTexture()->getSize());
	m_Sprite.setOrigin(textureSize * 0.5f);
	m_Sprite.setScale(100.0f / textureSize.x, 100.0f / textureSize.y);
	m_Sprite.setRotation(180);
}

void IconDeleter::Draw(sf::RenderWindow& window) const
{
	window.draw(m_Sprite);
}

void IconDeleter::DeleteRandomIcon()
{
	do
	{
		m_SelectedIconID = Utils::Random::GetInt(0, m_IconList.size() - 1);
		m_SelectedIcon = m_IconList[m_SelectedIconID];
	} while (m_SelectedIcon == nullptr);

	m_Sprite.setPosition(m_SelectedIcon->GetSprite().getPosition().x + 10.0f,
                         m_SelectedIcon->GetSprite().getPosition().y - 100.0f);

	auto* icon = m_IconList[m_SelectedIconID];
	m_IconList[m_SelectedIconID] = nullptr;
	m_SelectedIcon = nullptr;
	delete icon;
}
