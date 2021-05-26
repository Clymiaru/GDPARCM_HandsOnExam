#pragma once
#include <SFML/System/Vector2.hpp>

#include "ECS/Component/SpriteRendererComponent.h"

#include "AComponent.h"

class SpriteAnimatorComponent final : public AComponent
{
public:
	SpriteAnimatorComponent(Entity& owner,
							SpriteRendererComponent& spriteRenderer,
							sf::Vector2i frameSize,
							int spriteSheetMaxRows,
							int spriteSheetMaxCols,
							float timeBetweenFrames);
	~SpriteAnimatorComponent();

	MAKE_COMPONENT(SpriteAnimatorComponent)

	SpriteRendererComponent& GetSpriteRenderer() const;
	int GetFrameWidth() const;
	int GetFrameHeight() const;

	int GetCurrentRow() const;
	int GetCurrentCol() const;

	void AdvanceFrame();

	float GetElapsedTime() const;
	void UpdateTime(float time);

	float GetTimeBetweenFrames() const;

private:
	SpriteRendererComponent& m_Sprite;
	int m_FrameWidth;
	int m_FrameHeight;
	int m_MaxRows;
	int m_MaxCols;
	float m_TimeBetweenFrames;
	int m_CurrentRow;
	int m_CurrentCol;
	float m_TimeElapsed;
};
