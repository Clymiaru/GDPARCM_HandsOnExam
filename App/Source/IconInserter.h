#pragma once
#include <SFML/Graphics/Sprite.hpp>

#include "IconCodex.h"

#include "AssetManagement/Texture/Texture.h"

class IconInserter final
{
public:
	explicit IconInserter(Texture& texture,
                         IconCodex& iconCodex);
	
	void Draw(sf::RenderWindow& window) const;
	void InsertIcon();
private:
	sf::Sprite m_Sprite;
	Icon* m_SelectedIcon;
	IconCodex& m_IconCodex;
};
