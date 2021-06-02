#include "pch.h"
#include "Font.h"
#include "Utils/Debug.h"

Font::Font(StringRef name,
           StringRef filepath) :
	Asset(name, filepath)
{
	m_Data = new sf::Font();
	m_Data->loadFromFile(filepath);
	
	ASSERT(m_Data != nullptr,
	       AssetSystem,
	       "Font file (" << name << ", " << filepath << ") " << "cannot be loaded!")
	
	INFO_LOG(AssetSystem,
	         m_Name << " (" << GetTag() << ") has been loaded.")
}

Font::~Font()
{
	if (m_Data != nullptr)
	{
		delete m_Data;
		m_Data = nullptr;
	}
	
	INFO_LOG(AssetSystem,
	         m_Name << " (" << GetTag() << ") has been unloaded.")
}

sf::Font& Font::GetData() const
{
	return *m_Data;
}
