#include "pch.h"
#include "Music.h"
#include "Utils/Debug.h"

Music::Music(StringRef name,
             StringRef filepath) :
	Asset(name, filepath)
{
	m_Data = new sf::Music();
	m_Data->openFromFile(filepath);
	ASSERT(m_Data != nullptr,
	       AssetSystem,
	       "Music file (" << name << ", " << filepath << ") " << "cannot be loaded!")
	INFO_LOG(AssetSystem,
	         m_Name << " (" << GetTag() << ") has been loaded.")
}

Music::~Music()
{
	Stop();
	if (m_Data != nullptr)
	{
		delete m_Data;
		m_Data = nullptr;
	}
	INFO_LOG(AssetSystem,
	         m_Name << " (" << GetTag() << ") has been unloaded.")
}

void Music::Play() const
{
	if (m_Data->getStatus() != sf::Music::Playing)
		m_Data->play();
}

void Music::Pause() const
{
	if (m_Data->getStatus() == sf::Music::Playing)
		m_Data->pause();
}

void Music::Stop() const
{
	if (m_Data->getStatus() == sf::Music::Playing || m_Data->getStatus() == sf::Music::Paused)
		m_Data->stop();
}

void Music::SetVolume(const float volume) const
{
	m_Data->setVolume(volume);
}

void Music::EnableLooping(const bool flag) const
{
	m_Data->setLoop(flag);
}
