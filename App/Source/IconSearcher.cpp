#include "pch.h"
#include "IconSearcher.h"

#include "Utils/Random.h"

IconSearcher::IconSearcher(Texture& texture,
                           SharedIconCodexData& iconCodexData,
                           int id) :
	m_Sprite{texture.GetData()},
	m_SharedData{iconCodexData},
	m_SelectedIcon{nullptr},
	m_GoalIconID{-1},
	m_CurrentIconID{Utils::Random::GetInt(0, MAX_ACTIVE_ICON_COUNT - 1)},
	m_ID{id}
{
	const auto textureSize = static_cast<sf::Vector2f>(m_Sprite.getTexture()->getSize());
	m_Sprite.setOrigin(textureSize * 0.5f);
	m_Sprite.setScale(75.0f / textureSize.x, 75.0f / textureSize.y);
	m_Sprite.setPosition(-1000.0f,
                         -1000.0f);
}

void IconSearcher::Draw(sf::RenderWindow& window)
{
	SelectNextIcon();
	window.draw(m_Sprite);
}

void IconSearcher::SetSpritePosition()
{
	if (m_SelectedIcon == nullptr)
	{
		m_Sprite.setPosition(-1000.0f,
                         -1000.0f);
		return;
	}
	m_Sprite.setPosition(m_SelectedIcon->GetSprite().getPosition().x + 10.0f,
                        m_SelectedIcon->GetSprite().getPosition().y + 25.0f + 75.0f * m_ID);
}

bool IconSearcher::IsGoalIconSelected() const
{
	return m_CurrentIconID == m_GoalIconID;
}

void IconSearcher::Run()
{
	using namespace std::chrono_literals;

	while(true)
	{
		SetSpritePosition();
		m_SelectedIcon = nullptr;
		
		m_SharedData.DeleterIsRunning->acquire();
		m_SharedData.IconCodexLock->acquire();

		const auto anyIconsAvailable = m_SharedData.IconStorage->AreAnyIconsActive();
		if (!anyIconsAvailable)
		{
			m_SharedData.IconCodexLock->release();
			m_SharedData.DeleterIsRunning->release();
			continue;
		}
		m_SharedData.DeleterIsRunning->release();

		// Check if the selected icon and current position is the same

		if (m_GoalIconID == -1 || IsGoalIconSelected())
		{
			SelectARandomIcon();
			Sleep(100ms);
		}

		while (m_SelectedIcon == nullptr)
		{
			Icon* icon = m_SharedData.IconStorage->SelectIcon(m_CurrentIconID);
			if (icon != nullptr)
			{
				m_SelectedIcon = icon;
				break;;
			}
			SelectNextIcon();
		}


		//Sleep(10ms);

		m_SharedData.IconCodexLock->release();

	}
}

void IconSearcher::SelectARandomIcon()
{
	Icon* chosenIcon;
	do
	{
		m_GoalIconID = Utils::Random::GetInt(0, MAX_ACTIVE_ICON_COUNT - 1);
		chosenIcon = m_SharedData.IconStorage->SelectIcon(m_GoalIconID);
	} while (chosenIcon == nullptr);
}

void IconSearcher::SelectNextIcon()
{
	m_CurrentIconID = m_CurrentIconID + 1;
	if (m_CurrentIconID > MAX_ACTIVE_ICON_COUNT - 1)
	{
		m_CurrentIconID = 0;
	}
}

