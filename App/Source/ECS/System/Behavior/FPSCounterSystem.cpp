#include "pch.h"
#include "FPSCounterSystem.h"

FPSCounterSystem::FPSCounterSystem()
{
}

FPSCounterSystem::~FPSCounterSystem()
{
}

void FPSCounterSystem::Update(float deltaTime)
{
	for (auto* component : m_FPSCounterList)
	{
		component->UpdateFPS(deltaTime);
	}
}
