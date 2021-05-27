#pragma once
#include "IconCodex.h"

#include "AssetManagement/Texture/Texture.h"

class IconDeleter final
{
public:
	explicit IconDeleter(Texture& texture,
                         IconCodex& iconCodex);
	
	void Draw(sf::RenderWindow& window) const;
	void DeleteRandomIcon();
private:
	sf::Sprite m_Sprite;
	Icon* m_SelectedIcon;
	IconCodex& m_IconCodex;
};
