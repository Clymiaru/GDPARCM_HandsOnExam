#include "pch.h"
#include "IconDeleter.h"

IconDeleter::IconDeleter(Texture& texture,
                         SharedIconCodexData& iconCodexData) :
	m_Sprite{texture.GetData()},
	m_SharedData{iconCodexData},
	m_DeletedIcon{nullptr}
{
	const auto textureSize = static_cast<sf::Vector2f>(m_Sprite.getTexture()->getSize());
	m_Sprite.setOrigin(textureSize * 0.5f);
	m_Sprite.setScale(100.0f / textureSize.x, 100.0f / textureSize.y);
	m_Sprite.setRotation(180);
	m_Sprite.setPosition(-1000.0f,
                     -1000.0f);
}

void IconDeleter::Draw(sf::RenderWindow& window) const
{
	window.draw(m_Sprite);
}

void IconDeleter::SetSpritePosition()
{
	if (m_DeletedIcon == nullptr)
	{
		m_Sprite.setPosition(-1000.0f,
                         -1000.0f);
		return;
	}
	
	m_Sprite.setPosition(m_DeletedIcon->GetSprite().getPosition().x + 10.0f,
                        m_DeletedIcon->GetSprite().getPosition().y - 100.0f);
}

void IconDeleter::Run()
{
	using namespace std::chrono_literals;

	while (true)
	{
		SetSpritePosition();
		m_DeletedIcon = nullptr;

		m_SharedData.DeleterIsRunningLock->acquire();
		m_SharedData.InserterInProgressLock->acquire();
		m_SharedData.IconCodexLock->acquire();
		m_SharedData.DeleterIsRunningLock->release();
		m_SharedData.InserterInProgressLock->release();

		if (!AreAnyIconsAvailable())
		{
			m_SharedData.IconCodexLock->release();
			continue;
		}

		DeleteARandomIcon();
		std::cout << "Delete Icon at Pos " << m_DeletedIcon->GetPosition().x << "\n";

		m_SharedData.IconCodexLock->release();

		Sleep(145ms);
	}
}

void IconDeleter::DeleteARandomIcon()
{
	m_DeletedIcon = m_SharedData.IconStorage->HideRandomIcon();
}

bool IconDeleter::AreAnyIconsAvailable() const
{
	return m_SharedData.IconStorage->AreAnyIconsActive();
}

