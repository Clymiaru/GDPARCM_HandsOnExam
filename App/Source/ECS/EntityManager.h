#pragma once
#include "Entity.h"
class Entity;
class EntityManager final
{
public:
	static EntityManager& GetInstance();
	~EntityManager();

	Entity& CreateEntity(StringRef entityName);
	
	Entity* FindEntityByName(String entityName);

	void DestroyEntity(Entity& entity);

	void DestroyMarkedEntities();

	void DestroyAllEntities();

private:
	EntityManager();

	List<Entity*> m_EntityList;
	HashTable<String, Entity*> m_EntityTable;
	Queue<Entity*> m_DestroyedEntitiesQueue;
};
