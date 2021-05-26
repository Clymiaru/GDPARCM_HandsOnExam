#pragma once
#include "Entity.h"

enum class SystemType
{
	Event,
	Render,
	Behavior
};

#define MAKE_SYSTEM(system, systemType, componentClass, componentContainer)		\
	static SystemType GetSystemType() { return SystemType::systemType; }		\
	static String GetSystemName() { return #system; }							\
	virtual const char* GetName() const override { return #system; }			\
	virtual void MarkEntity(Entity& entity) override							\
	{																			\
		auto* component = entity.GetComponent<componentClass>();				\
		if (component == nullptr)												\
		{																		\
			return;																\
		}																		\
		componentContainer.push_back(component);								\
	}																			\
	virtual void UnmarkEntity(Entity& entity) override							\
	{																			\
		auto findComponentFunc = [entity](componentClass* other) -> bool		\
		{																		\
			const auto entityName = other->GetOwner().GetName();				\
			return entityName == entity.GetName();								\
		};																		\
		const auto foundComponent = std::ranges::find_if(componentContainer,	\
		                                                 findComponentFunc);	\
		if (foundComponent != componentContainer.end())							\
		{																		\
			componentContainer.erase(foundComponent);							\
		}																		\
	}																			

class Entity;

class ASystem
{
public:
	virtual ~ASystem() = default;
	virtual const char* GetName() const = 0;
	virtual void MarkEntity(Entity& entity) = 0;
	virtual void UnmarkEntity(Entity& entity) = 0;
};

