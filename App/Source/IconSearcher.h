#pragma once
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Sprite.hpp>

#include "AssetManagement/Texture/Texture.h"
#include "SharedIconCodexData.h"
#include "Threading/AThread.h"

class IconSearcher final : public AThread
{
public:
	explicit IconSearcher(Texture& texture,
	                      SharedIconCodexData& iconCodexData,
						  int id);
	~IconSearcher() override = default;
	
	void Draw(sf::RenderWindow& window);
	void SetSpritePosition();
	bool IsGoalIconSelected() const;
	void Run() override;
private:
	sf::Sprite m_Sprite;
	SharedIconCodexData& m_SharedData;

	Icon* m_SelectedIcon;
	int m_GoalIconID;
	int m_CurrentIconID;
	int m_ID;

	void SelectARandomIcon();
	void SelectNextIcon();
	bool AreAnyIconsAvailable() const;
};
