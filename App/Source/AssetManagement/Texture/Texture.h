#pragma once
#include "AssetManagement/Asset.h"
#include "SFML/Graphics/Texture.hpp"

class Texture final : public Asset
{
public:
	Texture(const Texture& other)                = delete;
	Texture(Texture&& other) noexcept            = delete;
	Texture& operator=(const Texture& other)     = delete;
	Texture& operator=(Texture&& other) noexcept = delete;
	Texture(StringRef name,
	        StringRef filepath);
	~Texture() override;
	MAKE_ASSET(Texture)
	sf::Texture& GetData() const;
private:
	sf::Texture* m_Data;
};
