#pragma once
#include "Icon.h"

// This will be a threaded approach
// Some functions here will be ran in threads
// All of them will be private

class IconCodex final
{
public:
	explicit IconCodex(List<Texture*>& iconTextures,
					   const sf::Vector2f& spriteSize);
	void DrawIcons(sf::RenderWindow& window);
	
	List<Icon*>& GetActiveIcons();
	int GetActiveIconsCount() const;
	void ShowIcons(int amount);
	void HideIcons(int amount);
	Icon* SelectIcon(int iconID);
private:
	List<Icon*> m_ActiveIcons;
	Queue<Icon*> m_InactiveIcons;
	Queue<sf::Vector2i> m_UnusedPositions;

	const int MaxIconSize = 10;
};
