#pragma once
#include "Utils/TypeAlias.h"

#define MAKE_COMPONENT(component)											\
	static String GetComponentName() { return #component; }					\
	virtual const char* GetName() const override { return #component; }

class Entity;
class AComponent
{
public:
	explicit AComponent(Entity& owner);
	virtual ~AComponent();
	
	Entity& GetOwner() const;
	
	virtual const char* GetName() const = 0;
	
protected:
	Entity& m_Owner;
};

