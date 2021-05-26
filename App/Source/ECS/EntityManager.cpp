#include "pch.h"
#include "EntityManager.h"

#include "Entity.h"

#include "ECS/EntitySystemManager.h"

#include "Utils/TypeAlias.h"

EntityManager::EntityManager()
{
}

EntityManager& EntityManager::GetInstance()
{
	static EntityManager instance;
	return instance;
}

EntityManager::~EntityManager()
{
}

Entity& EntityManager::CreateEntity(StringRef entityName)
{
	const auto isEntityExisted = m_EntityTable.find(entityName);

	ASSERT(isEntityExisted == m_EntityTable.end(),
		   EntitySystem,
		   "Attempting to create an entity with same name (" << entityName << ")")

	const auto entity = new Entity(entityName);
	m_EntityList.push_back(entity);
	m_EntityTable[entityName] = entity;
	return *entity;
}

Entity* EntityManager::FindEntityByName(String entityName)
{
	return m_EntityTable[entityName];
}

void EntityManager::DestroyEntity(Entity& entity)
{
	const auto foundEntity = std::ranges::find_if(m_EntityList,
	                                              [entity](Entity* other) -> bool
	                                              {
		                                              return entity.GetName() == other->GetName();
	                                              });
	                                              
	if (foundEntity != m_EntityList.end())
	{
		m_DestroyedEntitiesQueue.push(*foundEntity);
		m_EntityTable.erase(entity.GetName());
		m_EntityList.erase(foundEntity);
		m_EntityList.shrink_to_fit();
	}
}

void EntityManager::DestroyMarkedEntities()
{
	while (!m_DestroyedEntitiesQueue.empty())
	{
		auto* entity = m_DestroyedEntitiesQueue.front();
		m_DestroyedEntitiesQueue.pop();
		INFO_LOG(EntitySystem, "Entity " << entity->GetName() << " destroyed!" )
		EntitySystemManager::GetInstance().UnmarkEntityInRegisteredSystems(*entity);
		delete entity;
	}
}

void EntityManager::DestroyAllEntities()
{
	for (auto* entity : m_EntityList)
	{
		DestroyEntity(*entity);
	}
}


