#pragma once
#include <SFML/Graphics.hpp>

#include "AssetManagement/Texture/Texture.h"

class Icon final
{
public:
	explicit Icon(Texture& texture,
	              const sf::Vector2i& position = sf::Vector2i(0, 0));
	~Icon();

	sf::Sprite& GetSprite();

	void SetSize(const sf::Vector2f& spriteSize);

	void SetPosition(const sf::Vector2i& position,
					 const sf::Vector2f& worldOffset = sf::Vector2f(0.0f, 0.0f),
					 float spacing = 0.0f);
private:
	sf::Vector2i m_Position;
	sf::Vector2f m_SpriteSize;
	sf::Sprite m_Sprite;

	void UpdateSpritePosition(const sf::Vector2f& worldOffset = sf::Vector2f(0.0f, 0.0f),
							  float spacing = 0.0f);
};
