#pragma once
#include "AComponent.h"
#include "TextComponent.h"

class FPSCounterComponent final : public AComponent
{
public:
	FPSCounterComponent(Entity& owner, TextComponent& textComponent);
	~FPSCounterComponent();

	MAKE_COMPONENT(FPSCounterComponent)

	void UpdateFPS(float deltaTime);
	float GetFPS() const;

private:
	TextComponent& m_TextComponent;
	int m_Frames;
	float m_ElapsedTime;
};
