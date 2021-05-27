#include "pch.h"
#include "IconInserter.h"

IconInserter::IconInserter(Texture& texture,
						   List<Icon*>& iconList):
	m_Sprite{texture.GetData()},
	m_SelectedIconID{0},
	m_SelectedIcon{nullptr},
	m_IconList{iconList}
{
}

void IconInserter::Draw(sf::RenderWindow& window) const
{
}

void IconInserter::InsertRandomIcon()
{
}
