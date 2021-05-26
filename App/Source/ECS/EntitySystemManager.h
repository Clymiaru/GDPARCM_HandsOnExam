#pragma once
#include <SFML/Graphics/RenderWindow.hpp>

#include "ASystem.h"
class Event;

class EntitySystemManager
{
public:
	static EntitySystemManager& GetInstance();
	~EntitySystemManager();

	template <class System>
	System* GetSystem();

	template <class System>
    void MarkEntity(Entity& entity);

	template <class System>
    void UnmarkEntity(Entity& entity);

	void ProcessEvents(Event& event);
	void Render(sf::RenderWindow& window);
	void Update(float deltaTime);

	void MarkEntityInRegisteredSystems(Entity& entity);
	void UnmarkEntityInRegisteredSystems(Entity& entity);

private:
	EntitySystemManager();
	
	List<ASystem*> m_RegisteredSystemList;
	HashTable<String, ASystem*> m_RegisteredSystemTable;
	HashTable<SystemType, List<ASystem*>> m_RegisteredSystemByTypeTable;
};

template <class System>
System* EntitySystemManager::GetSystem()
{
	auto* foundSystem = m_RegisteredSystemTable[System::GetSystemName()];
	if (foundSystem == nullptr)
	{
		System* system = new System();
		m_RegisteredSystemList.push_back(system);
		m_RegisteredSystemTable[System::GetSystemName()] = system;
		m_RegisteredSystemByTypeTable[System::GetSystemType()].push_back(system);
		return system;
	}
	return static_cast<System*>(foundSystem);
}

template <class System>
void EntitySystemManager::MarkEntity(Entity& entity)
{
	auto* foundSystem = m_RegisteredSystemTable[System::GetSystemName()]; 
	ASystem* system = foundSystem;
	
	if (system == nullptr)
	{
		system = new System();
		m_RegisteredSystemList.push_back(system);
		m_RegisteredSystemTable[System::GetSystemName()] = system;
		m_RegisteredSystemByTypeTable[System::GetSystemType()].push_back(system);
	}
	
	system->MarkEntity(entity);
}

template <class System>
void EntitySystemManager::UnmarkEntity(Entity& entity)
{
	auto* foundSystem = m_RegisteredSystemTable[System::GetSystemName()]; 
	ASystem* system = foundSystem;
	
	if (system == nullptr)
	{
		system = new System();
		m_RegisteredSystemList.push_back(system);
		m_RegisteredSystemTable[System::GetSystemName()] = system;
		m_RegisteredSystemByTypeTable[System::GetSystemType()].push_back(system);
	}
	
	system->UnmarkEntity(entity);
}
