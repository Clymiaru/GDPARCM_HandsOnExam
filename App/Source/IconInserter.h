#pragma once
#include <SFML/Graphics/Sprite.hpp>

#include "SharedIconCodexData.h"
#include "AssetManagement/Texture/Texture.h"
#include "Threading/AThread.h"

class IconInserter final : public AThread
{
public:
	explicit IconInserter(Texture& texture,
	                      SharedIconCodexData& iconCodexData);
	~IconInserter() override = default;
	
	void Draw(sf::RenderWindow& window) const;
	void SetSpritePosition();

	void Run() override;
private:
	sf::Sprite m_Sprite;
	SharedIconCodexData& m_SharedData;
	
	Icon* m_InsertedIcon;

	void InsertIconAtAvailableLocation();
};
