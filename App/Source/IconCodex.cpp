#include "pch.h"
#include "IconCodex.h"

#include "AssetManagement/Texture/Textures.h"
#include "Utils/Random.h"
#include "BaseRunner.h"

void IconCodex::GenerateUnusedPositions()
{
	for (auto i = 0; i < MAX_ACTIVE_ICON_COUNT; i++)
	{
		m_UnusedPositions.push({i, 0});
	}
}

void IconCodex::InitializeIconsAsInactive(List<Texture*>& iconTextures,
										  const sf::Vector2f& spriteSize)
{
	for (auto i = 0; i < iconTextures.size(); i++)
	{
		auto icon = new Icon(*iconTextures[i], {-1, 0});
		icon->SetSize(spriteSize);
		m_InactiveIcons.push(icon);
	}
}

void IconCodex::InitializeActiveIconList()
{
	for (auto i = 0; i < MAX_ACTIVE_ICON_COUNT; i++)
	{
		m_ActiveIcons[i] = nullptr;
	}
}

IconCodex::IconCodex(List<Texture*>& iconTextures,
                     const sf::Vector2f& spriteSize)
{
	InitializeActiveIconList();
	InitializeIconsAsInactive(iconTextures, spriteSize);
	GenerateUnusedPositions();
}

void IconCodex::DrawIcons(sf::RenderWindow& window)
{
	for (auto* icon : m_ActiveIcons)
	{
		if (icon != nullptr)
		{
			window.draw(icon->GetSprite());
		}
	}
}

Icon* IconCodex::ShowIcon()
{
	auto* toShowIcon = m_InactiveIcons.front();
	m_InactiveIcons.pop();
	
	const auto iconPosition = m_UnusedPositions.front();
	m_UnusedPositions.pop();
		
	toShowIcon->SetPosition(iconPosition,
              {65.0f, BaseRunner::WindowSize.Height / 2.0f},
                 25.0f);

	m_ActiveIcons[iconPosition.x] = toShowIcon;
	return toShowIcon;
}

Icon* IconCodex::HideRandomIcon()
{
	if (!AreAnyIconsActive())
	{
		return nullptr;
	}
	
	Icon* toHideIcon;
	do
	{
		const auto iconIndex = Utils::Random::GetInt(0, static_cast<int>(m_ActiveIcons.size()) - 1);
		toHideIcon     = m_ActiveIcons[iconIndex];
		

	} while (toHideIcon == nullptr);
	
	m_UnusedPositions.push(toHideIcon->GetPosition());
	m_InactiveIcons.push(toHideIcon);
	
	m_ActiveIcons[toHideIcon->GetPosition().x] = nullptr;

	return toHideIcon;
}

void IconCodex::ShowIcons(const int amount)
{
	for (auto i = 0; i < amount; i++)
	{
		ShowIcon();
	}
}

Icon* IconCodex::SelectIcon(const int iconID)
{
	return m_ActiveIcons[iconID];
}

bool IconCodex::AreAnyIconsActive()
{
	auto count = 0;
	for (auto* icon : m_ActiveIcons)
	{
		if (icon != nullptr)
		{
			count++;
		}
	}
	return count > 0;
}

bool IconCodex::IsActiveIconsFull()
{
	auto count = 0;
	for (auto* icon : m_ActiveIcons)
	{
		if (icon != nullptr)
		{
			count++;
		}
	}
	return count == MAX_ACTIVE_ICON_COUNT;
}
