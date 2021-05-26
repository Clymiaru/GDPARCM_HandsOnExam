#include "pch.h"
#include "SpriteRendererSystem.h"

SpriteRendererSystem::SpriteRendererSystem()
{
}

SpriteRendererSystem::~SpriteRendererSystem()
{
}

void SpriteRendererSystem::Render(sf::RenderWindow& window)
{
	for (auto* component : m_SpriteRendererComponentList)
	{
		auto transform = component->GetTransform();
		auto sprite = component->GetSprite();
		window.draw(sprite, transform);
	}
}
