#pragma once

#include "Icon.h"

const int MAX_ACTIVE_ICON_COUNT = 10;

class IconCodex final
{
public:
	explicit IconCodex(List<Texture*>& iconTextures,
	                   const sf::Vector2f& spriteSize);
	void DrawIcons(sf::RenderWindow& window);
	
	Icon* ShowIcon();
	Icon* HideRandomIcon();
	
	void ShowIcons(int amount);
	Icon* SelectIcon(int iconID);

	bool AreAnyIconsActive();
	bool IsActiveIconsFull();
private:
	Array<Icon*, 10> m_ActiveIcons;
	Queue<Icon*> m_InactiveIcons;
	Queue<sf::Vector2i> m_UnusedPositions;

	void GenerateUnusedPositions();
	void InitializeIconsAsInactive(List<Texture*>& iconTextures,
	                               const sf::Vector2f& spriteSize);
	void InitializeActiveIconList();
};
