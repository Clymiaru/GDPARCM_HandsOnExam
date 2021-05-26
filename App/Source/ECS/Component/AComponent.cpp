#include "pch.h"
#include "AComponent.h"

AComponent::AComponent(Entity& owner) :
    m_Owner{owner}
{
}

AComponent::~AComponent()
{
}

Entity& AComponent::GetOwner() const
{
	return m_Owner;
}
