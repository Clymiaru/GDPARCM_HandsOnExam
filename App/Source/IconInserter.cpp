#include "pch.h"
#include "IconInserter.h"

#include "Utils/Random.h"

IconInserter::IconInserter(Texture& texture,
                           SharedIconCodexData& iconCodexData) :
	m_Sprite{texture.GetData()},
	m_SharedData{iconCodexData},
	m_InsertedIcon{nullptr}
{
	const auto textureSize = static_cast<sf::Vector2f>(m_Sprite.getTexture()->getSize());
	m_Sprite.setOrigin(textureSize * 0.5f);
	m_Sprite.setScale(100.0f / textureSize.x, 100.0f / textureSize.y);
	m_Sprite.setRotation(180);
	m_Sprite.setPosition(-1000.0f,
                     -1000.0f);
}

void IconInserter::Draw(sf::RenderWindow& window) const
{
	window.draw(m_Sprite);
}

void IconInserter::SetSpritePosition()
{
	if (m_InsertedIcon == nullptr)
	{
		m_Sprite.setPosition(-1000.0f,
                         -1000.0f);
		return;
	}
	
	m_Sprite.setPosition(m_InsertedIcon->GetSprite().getPosition().x + 10.0f,
                        m_InsertedIcon->GetSprite().getPosition().y - 200.0f);
}

void IconInserter::Run()
{
	using namespace std::chrono_literals;
	
	while (true)
	{
		SetSpritePosition();
		m_InsertedIcon = nullptr;

		Sleep(250ms);
		
		m_SharedData.DeleterIsRunning->acquire();
		m_SharedData.IconCodexLock->acquire();
		
		const auto isActiveIconListFull = m_SharedData.IconStorage->IsActiveIconsFull();
		if (isActiveIconListFull)
		{
			m_SharedData.IconCodexLock->release();
			m_SharedData.DeleterIsRunning->release();
			continue;
		}
		m_SharedData.DeleterIsRunning->release();
		
		InsertIconAtAvailableLocation();
		std::cout << "Insert Icon at Pos " << m_InsertedIcon->GetPosition().x << "\n";

		m_SharedData.IconCodexLock->release();

		
	}
}

void IconInserter::InsertIconAtAvailableLocation()
{
	m_InsertedIcon = m_SharedData.IconStorage->ShowIcon();
}



