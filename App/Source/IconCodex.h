#pragma once
#include "Icon.h"

// This will be a threaded approach
// Some functions here will be ran in threads
// All of them will be private

class IconCodex final
{
public:
	IconCodex();
	void DrawIcons(sf::RenderWindow& window);
	
	List<Icon*>& GetIconList();
private:
	List<Icon*> m_IconList;
};
