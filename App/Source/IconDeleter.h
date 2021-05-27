#pragma once
#include "Icon.h"

#include "AssetManagement/Texture/Texture.h"

class IconDeleter final
{
public:
	explicit IconDeleter(Texture& texture,
                         List<Icon*>& iconList);
	
	void Draw(sf::RenderWindow& window) const;
	void DeleteRandomIcon();
private:
	sf::Sprite m_Sprite;
	int m_SelectedIconID;
	Icon* m_SelectedIcon;
	List<Icon*>& m_IconList;
};
