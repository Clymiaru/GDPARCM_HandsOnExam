#pragma once
#include <functional>

#include "SpriteRendererComponent.h"

#include "ECS/Component/AComponent.h"

class AlphaFadeTransitionComponent final : public AComponent
{
public:
	AlphaFadeTransitionComponent(Entity& owner,
								   SpriteRendererComponent& spriteRendererComponent,
								   float initialAlpha,
								   float finalAlpha,
								   float duration,
								   std::function<float(float, float, float, float)> fadeFunction);
	
	MAKE_COMPONENT(AlphaFadeTransitionComponent)

	void UpdateElapsedTime(float deltaTime);

	SpriteRendererComponent& GetSprite() const;
	float GetCurrentAlpha();
private:
	SpriteRendererComponent& m_Sprite;
	float m_InitialAlpha;
	float m_FinalAlpha;
	float m_StartingTimeInSeconds;
	float m_DurationInSeconds;
	float m_ElapsedTime;
	std::function<float(float,float,float,float)> m_FadeFormula;
};
