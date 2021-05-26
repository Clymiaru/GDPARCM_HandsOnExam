#include "pch.h"
#include "AScene.h"

#include "ECS/EntityManager.h"

AScene::AScene(StringRef name) :
	m_Name(name),
	m_HasLoadedResources(false)
{
}

void AScene::LoadResources()
{
	if (!m_HasLoadedResources)
	{
		m_HasLoadedResources = true;
		LoadResourcesImpl();
	}
}

StringRef AScene::GetName() const
{
	return m_Name;
}