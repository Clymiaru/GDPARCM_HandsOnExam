#include "pch.h"
#include "Sound.h"
#include "Utils/Debug.h"

Sound::Sound(const String& name,
             const String& filepath) :
	Asset(name, filepath)
{
	m_BufferData = new sf::SoundBuffer();
	m_BufferData->loadFromFile(filepath);
	m_SoundData = new sf::Sound(*m_BufferData);
	ASSERT(m_BufferData != nullptr,
	       AssetSystem,
	       "Sound file (" << name << ", " << filepath << ") " << "cannot be loaded!")
	INFO_LOG(AssetSystem,
	         m_Name << " (" << GetTag() << ") has been loaded.")
}

Sound::~Sound()
{
	Stop();
	if (m_SoundData != nullptr)
	{
		delete m_SoundData;
		m_SoundData = nullptr;
	}
	if (m_BufferData != nullptr)
	{
		delete m_BufferData;
		m_BufferData = nullptr;
	}
	INFO_LOG(AssetSystem,
	         m_Name << " (" << GetTag() << ") has been unloaded.")
}

void Sound::Play() const
{
	if (m_SoundData->getStatus() != sf::Sound::Playing)
		m_SoundData->play();
}

void Sound::Pause() const
{
	if (m_SoundData->getStatus() == sf::Sound::Playing)
		m_SoundData->pause();
}

void Sound::Stop() const
{
	if (m_SoundData->getStatus() == sf::Sound::Playing || m_SoundData->getStatus() == sf::Sound::Paused)
		m_SoundData->stop();
}

void Sound::SetVolume(const float volume) const
{
	m_SoundData->setVolume(volume);
}
