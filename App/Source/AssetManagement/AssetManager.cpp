#include "pch.h"
#include "AssetManager.h"

AssetManager& AssetManager::GetInstance()
{
	static AssetManager instance;
	return instance;
}

AssetManager::~AssetManager()
{
	m_AssetStorage.clear();
}

AssetManager::AssetManager()
{
}
