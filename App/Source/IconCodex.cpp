#include "pch.h"
#include "IconCodex.h"

#include "AssetManagement/Texture/Textures.h"
#include "Utils/Random.h"
#include "BaseRunner.h"

// {
// 	auto& assetManager = AssetManager::GetInstance();
// 	

//
// 	for (auto i = 0; i < 10; i++)
// 	{
// 		auto icon = new Icon(*assetIcons[i], {i, 0});
// 		icon->SetSize({100.0f, 100.0f});
// 		icon->SetPosition( {i, 0},
// 				  {65.0f, BaseRunner::WindowSize.Height / 2.0f},
// 				     25.0f);
// 		m_IconList.push_back(icon);
// 	}
// }

IconCodex::IconCodex(List<Texture*>& iconTextures,
					 const sf::Vector2f& spriteSize)
{
	for (auto i = 0; i < iconTextures.size(); i++)
	{
		auto icon = new Icon(*iconTextures[i], {-1, 0});
		icon->SetSize(spriteSize);
		m_InactiveIcons.push(icon);
	}

	for (auto i = 0; i < MaxIconSize; i++)
	{
		m_UnusedPositions.push({i, 0});
	}
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

List<Icon*>& IconCodex::GetActiveIcons()
{
	return m_ActiveIcons;
}

int IconCodex::GetActiveIconsCount() const
{
	return m_ActiveIcons.size();
}

void IconCodex::ShowIcons(const int amount)
{
	if (static_cast<int>(m_ActiveIcons.size()) + amount > MaxIconSize)
	{
		std::cout << "Attempting to show more than 10 icons!\n"; 
		return;
	}
	
	for (auto i = 0; i < amount; i++)
	{
		auto* icon = m_InactiveIcons.front();
		m_InactiveIcons.pop();

		sf::Vector2i iconPosition = m_UnusedPositions.front();
		m_UnusedPositions.pop();
		
		icon->SetPosition( iconPosition,
		          {65.0f, BaseRunner::WindowSize.Height / 2.0f},
		             25.0f);

		m_ActiveIcons.push_back(icon);
	}
}

void IconCodex::HideIcons(const int amount)
{
	if (static_cast<int>(m_ActiveIcons.size()) - amount < 0)
	{
		std::cout << "Attempting to hide more than the active icons!\n"; 
		return;
	}
	
	for (auto i = 0; i < amount; i++)
	{
		auto iconID = 0;
		Icon* toHideIcon = nullptr;
		
		do
		{
			iconID = Utils::Random::GetInt(0, m_ActiveIcons.size() - 1);
			toHideIcon = m_ActiveIcons[iconID];
		} while (toHideIcon == nullptr);
		
		m_ActiveIcons.erase(m_ActiveIcons.begin() + iconID);
		m_UnusedPositions.push(toHideIcon->GetPosition());
	}
}

Icon* IconCodex::SelectIcon(const int iconID)
{
	if (iconID < 0 ||
		iconID > m_ActiveIcons.size() - 1)
	{
		std::cout << "Attempting to select an Icon that is not active!\n";
		return nullptr;
	}

	return m_ActiveIcons[iconID];
}
