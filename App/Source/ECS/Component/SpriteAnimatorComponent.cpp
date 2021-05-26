#include "pch.h"
#include "SpriteAnimatorComponent.h"
#include "ECS/Entity.h"
SpriteAnimatorComponent::SpriteAnimatorComponent(Entity& owner,
												 SpriteRendererComponent& spriteRenderer,
												 const sf::Vector2i frameSize,
												 const int spriteSheetMaxRows,
												 const int spriteSheetMaxCols,
												 const float timeBetweenFrames) :
	AComponent{owner},
	m_Sprite{spriteRenderer},
	m_FrameWidth{frameSize.x},
	m_FrameHeight{frameSize.y},
	m_MaxRows{spriteSheetMaxRows},
	m_MaxCols{spriteSheetMaxCols},
	m_TimeBetweenFrames{timeBetweenFrames},
	m_CurrentRow{0},
	m_CurrentCol{0},
	m_TimeElapsed{0.0f}
{
}

SpriteAnimatorComponent::~SpriteAnimatorComponent()
{
}

SpriteRendererComponent& SpriteAnimatorComponent::GetSpriteRenderer() const
{
	return m_Sprite;
}

int SpriteAnimatorComponent::GetFrameWidth() const
{
	return m_FrameWidth;
}

int SpriteAnimatorComponent::GetFrameHeight() const
{
	return m_FrameHeight;
}

int SpriteAnimatorComponent::GetCurrentRow() const
{
	return m_CurrentRow;
}

int SpriteAnimatorComponent::GetCurrentCol() const
{
	return m_CurrentCol;
}

void SpriteAnimatorComponent::AdvanceFrame()
{
	m_CurrentCol++;
	if (m_CurrentCol >= m_MaxCols)
	{
		m_CurrentCol = 0;
		m_CurrentRow++;
	}

	if (m_CurrentRow >= m_MaxRows)
	{
		m_CurrentRow = 0;
	}

	m_TimeElapsed = 0.0f;
}

float SpriteAnimatorComponent::GetElapsedTime() const
{
	return m_TimeElapsed;
}

void SpriteAnimatorComponent::UpdateTime(const float time)
{
	m_TimeElapsed += time;
}

float SpriteAnimatorComponent::GetTimeBetweenFrames() const
{
	return m_TimeBetweenFrames;
}
