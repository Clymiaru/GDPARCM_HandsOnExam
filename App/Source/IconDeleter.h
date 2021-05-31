#pragma once

#include "SharedIconCodexData.h"
#include "AssetManagement/Texture/Texture.h"
#include "Threading/AThread.h"

class IconDeleter final : public AThread
{
public:
	explicit IconDeleter(Texture& texture,
	                     SharedIconCodexData& iconCodexData);
	~IconDeleter() override = default;
	
	void Draw(sf::RenderWindow& window) const;
	void SetSpritePosition();

	void Run() override;
private:
	sf::Sprite m_Sprite;
	SharedIconCodexData& m_SharedData;
	
	Icon* m_DeletedIcon;

	void DeleteARandomIcon();
};
