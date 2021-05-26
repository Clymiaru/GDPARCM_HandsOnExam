#pragma once
#include <SFML/Graphics/RenderWindow.hpp>

#include "ECS/Component/SpriteRendererComponent.h"
#include "ECS/ASystem.h"
#include "ECS/ARenderSystem.h"

class SpriteRendererSystem final : public ARenderSystem
{
public:
	SpriteRendererSystem();
	~SpriteRendererSystem() override;

	MAKE_SYSTEM(SpriteRendererSystem,
             Render,
          SpriteRendererComponent,
       m_SpriteRendererComponentList)

	void Render(sf::RenderWindow& window) override;

private:
	List<SpriteRendererComponent*> m_SpriteRendererComponentList;
};
