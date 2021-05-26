#pragma once
#include "AssetManagement/Asset.h"
#include "SFML/Audio/Music.hpp"

class Music final : public Asset
{
public:
	Music(const Music& other)                = delete;
	Music(Music&& other) noexcept            = delete;
	Music& operator=(const Music& other)     = delete;
	Music& operator=(Music&& other) noexcept = delete;
	Music(StringRef name,
	      StringRef filepath);
	~Music() override;
	void Play() const;
	void Pause() const;
	void Stop() const;
	void SetVolume(float volume) const;
	void EnableLooping(bool flag) const;
	MAKE_ASSET(Music)
private:
	sf::Music* m_Data = nullptr;
};
