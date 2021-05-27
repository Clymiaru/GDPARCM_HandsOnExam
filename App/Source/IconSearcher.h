#pragma once
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Sprite.hpp>

#include "Icon.h"

#include "AssetManagement/Texture/Texture.h"

class IconSearcher
{
public:
	explicit IconSearcher(Texture& texture,
						  List<Icon*>& iconList);
	void Draw(sf::RenderWindow& window) const;
	void SelectNextIcon();
private:
	sf::Sprite m_Sprite;
	int m_SelectedIconID;
	Icon* m_SelectedIcon;
	List<Icon*>& m_IconList;
};
