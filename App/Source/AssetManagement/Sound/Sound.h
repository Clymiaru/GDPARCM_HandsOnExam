#pragma once
#include "AssetManagement/Asset.h"
#include "SFML/Audio/SoundBuffer.hpp"
#include "SFML/Audio/Sound.hpp"

class Sound final : public Asset
{
public:
	Sound(const Sound& other)                = delete;
	Sound(Sound&& other) noexcept            = delete;
	Sound& operator=(const Sound& other)     = delete;
	Sound& operator=(Sound&& other) noexcept = delete;
	Sound(StringRef name,
	      StringRef filepath);
	~Sound() override;
	void Play() const;
	void Pause() const;
	void Stop() const;
	void SetVolume(float volume) const;
	MAKE_ASSET(SFX)
private:
	sf::SoundBuffer* m_BufferData = nullptr;
	sf::Sound* m_SoundData        = nullptr;
};
