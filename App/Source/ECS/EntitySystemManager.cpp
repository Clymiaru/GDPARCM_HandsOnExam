#include "pch.h"
#include "EntitySystemManager.h"
#include "ABehaviorSystem.h"
#include "AEventSystem.h"
#include "ARenderSystem.h"

EntitySystemManager& EntitySystemManager::GetInstance()
{
	static EntitySystemManager instance;
	return instance;
}

EntitySystemManager::~EntitySystemManager()
{
}

void EntitySystemManager::ProcessEvents(Event& event)
{
	for (auto* system : m_RegisteredSystemByTypeTable[SystemType::Event])
	{
		auto* eventSystem = static_cast<AEventSystem*>(system);
		eventSystem->ProcessEvent(event);
	}
}

void EntitySystemManager::Render(sf::RenderWindow& window)
{
	for (auto* system : m_RegisteredSystemByTypeTable[SystemType::Render])
	{
		auto* renderSystem = static_cast<ARenderSystem*>(system);
		renderSystem->Render(window);
	}
}

void EntitySystemManager::Update(const float deltaTime)
{
	for (auto* system : m_RegisteredSystemByTypeTable[SystemType::Behavior])
	{
		auto* behaviorSystem = static_cast<ABehaviorSystem*>(system);
		behaviorSystem->Update(deltaTime);
	}
}

void EntitySystemManager::MarkEntityInRegisteredSystems(Entity& entity)
{
	for (auto* system : m_RegisteredSystemList)
	{
		system->MarkEntity(entity);
	}
}

void EntitySystemManager::UnmarkEntityInRegisteredSystems(Entity& entity)
{
	for (auto* system : m_RegisteredSystemList)
	{
		system->UnmarkEntity(entity);
	}
}

EntitySystemManager::EntitySystemManager()
{
}
