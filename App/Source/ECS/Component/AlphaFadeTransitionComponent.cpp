#include "pch.h"
#include "AlphaFadeTransitionComponent.h"

AlphaFadeTransitionComponent::AlphaFadeTransitionComponent(Entity& owner,
																SpriteRendererComponent& spriteRendererComponent,
																float initialAlpha,
																float finalAlpha,
																float duration,
																std::function<float(float, float, float, float)> fadeFunction) :
	AComponent{owner},
	m_Sprite{spriteRendererComponent},
	m_InitialAlpha{initialAlpha},
	m_FinalAlpha{finalAlpha},
	m_StartingTimeInSeconds{0},
	m_DurationInSeconds{duration},
	m_ElapsedTime{0.0f},
	m_FadeFormula{fadeFunction}
{
}

void AlphaFadeTransitionComponent::UpdateElapsedTime(float deltaTime)
{
	m_ElapsedTime += deltaTime;
}

SpriteRendererComponent& AlphaFadeTransitionComponent::GetSprite() const
{
	return m_Sprite;
}

float AlphaFadeTransitionComponent::GetCurrentAlpha()
{
	auto currentTime        = m_ElapsedTime;
	currentTime             = std::max(currentTime, 0.0f);
	m_DurationInSeconds     = std::max(m_DurationInSeconds, 0.0000001f);
	const auto currentAlpha = m_FadeFormula(currentTime, m_InitialAlpha, m_FinalAlpha, m_DurationInSeconds);
	return std::clamp(currentAlpha, 0.0f, 1.0f);
}
