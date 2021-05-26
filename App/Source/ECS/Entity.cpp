#include "pch.h"
#include "Entity.h"

#include "EntityManager.h"
#include "ECS/Component/AComponent.h"

Entity::Entity(StringRef name) :
	m_Name{name}
{
}

StringRef Entity::GetName() const
{
	return m_Name;
}

void Entity::SetName(StringRef name)
{
	m_Name = name;
}