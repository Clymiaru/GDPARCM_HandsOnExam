#include "pch.h"
#include "IconCodex.h"

#include "AssetManagement/AssetManager.h"
#include "AssetManagement/Texture/Textures.h"

#include "BaseRunner.h"

IconCodex::IconCodex()
{
	auto& assetManager = AssetManager::GetInstance();
	
	List<Texture*> assetIcons;
	assetIcons.emplace_back(&assetManager.Acquire<Texture>(TextureNames::REI_ICON));
	assetIcons.emplace_back(&assetManager.Acquire<Texture>(TextureNames::YUI_ICON));
	assetIcons.emplace_back(&assetManager.Acquire<Texture>(TextureNames::MIMI_ICON));
	assetIcons.emplace_back(&assetManager.Acquire<Texture>(TextureNames::RIMA_ICON));
	assetIcons.emplace_back(&assetManager.Acquire<Texture>(TextureNames::HIYORI_ICON));
	assetIcons.emplace_back(&assetManager.Acquire<Texture>(TextureNames::KYOUKA_ICON));
	assetIcons.emplace_back(&assetManager.Acquire<Texture>(TextureNames::MISOGI_ICON));
	assetIcons.emplace_back(&assetManager.Acquire<Texture>(TextureNames::SHIORI_ICON));
	assetIcons.emplace_back(&assetManager.Acquire<Texture>(TextureNames::RANGER_RIN_ICON));
	assetIcons.emplace_back(&assetManager.Acquire<Texture>(TextureNames::RANGER_MAHIRU_ICON));

	for (auto i = 0; i < 10; i++)
	{
		auto icon = new Icon(*assetIcons[i], {i, 0});
		icon->SetSize({100.0f, 100.0f});
		icon->SetPosition( {i, 0},
				  {65.0f, BaseRunner::WindowSize.Height / 2.0f},
				     25.0f);
		m_IconList.push_back(icon);
	}
}

void IconCodex::DrawIcons(sf::RenderWindow& window)
{
	for (auto* icon : m_IconList)
	{
		if (icon != nullptr)
		{
			window.draw(icon->GetSprite());
		}
	}
}

List<Icon*>& IconCodex::GetIconList()
{
	return m_IconList;
}
