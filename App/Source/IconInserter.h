#pragma once
#include <SFML/Graphics/Sprite.hpp>

#include "Icon.h"

#include "AssetManagement/Texture/Texture.h"

class IconInserter final
{
public:
	explicit IconInserter(Texture& texture,
                         List<Icon*>& iconList);
	
	void Draw(sf::RenderWindow& window) const;
	void InsertRandomIcon();
private:
	sf::Sprite m_Sprite;
	int m_SelectedIconID;
	Icon* m_SelectedIcon;
	List<Icon*>& m_IconList;
};
