#include "pch.h"
#include "Texture.h"
#include "Utils/Debug.h"

Texture::Texture(StringRef name,
                 StringRef filepath) :
	Asset(name, filepath)
{
	m_Data = new sf::Texture();
	m_Data->loadFromFile(filepath);
	ASSERT(m_Data != nullptr,
	       AssetSystem,
	       "Texture file (" << name << ", " << filepath << ") " << "cannot be loaded!")
	INFO_LOG(AssetSystem,
	         m_Name << " (" << GetTag() << ") has been loaded.")
}

Texture::~Texture()
{
	if (m_Data != nullptr)
	{
		delete m_Data;
		m_Data = nullptr;
	}
	INFO_LOG(AssetSystem,
	         m_Name << " (" << GetTag() << ") has been unloaded.")
}

sf::Texture& Texture::GetData() const
{
	return *m_Data;
}
