#include "pch.h"
#include "FPSCounterComponent.h"

FPSCounterComponent::FPSCounterComponent(Entity& owner, TextComponent& textComponent) :
	AComponent{owner},
	m_TextComponent{textComponent},
	m_Frames{0},
	m_ElapsedTime{0.0f}
{
}

FPSCounterComponent::~FPSCounterComponent()
{
}

void FPSCounterComponent::UpdateFPS(float deltaTime)
{
	m_Frames++;
	m_ElapsedTime += deltaTime;

	if (m_ElapsedTime > 1.0f)
	{
		m_TextComponent.UpdateText("FPS: " + std::to_string(m_Frames));
		m_Frames = 0;
		m_ElapsedTime = 0.0f;
	}
}

float FPSCounterComponent::GetFPS() const
{
	return static_cast<float>(m_Frames);
}
