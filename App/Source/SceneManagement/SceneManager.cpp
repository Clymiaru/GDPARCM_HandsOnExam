#include "pch.h"
#include "SceneManager.h"

#include <mutex>

#include "Utils/Debug.h"

SceneManager::SceneManager()
{
}

SceneManager& SceneManager::GetInstance()
{
	static SceneManager instance;
	return instance;
}

SceneManager::~SceneManager()
{
}

void SceneManager::RegisterScenes(List<AScene*> scenes)
{
	for (auto* scene : scenes)
	{
		ASSERT(scene != nullptr, SceneSystem, "Attempting to register a NULL scene!");
		const auto hasSceneBeenRegistered = m_SceneStorage.find(scene->GetName()) != m_SceneStorage.end();
		ASSERT(!hasSceneBeenRegistered, SceneSystem, scene->GetName() << " has already been registered!")
		m_SceneStorage[scene->GetName()] = scene;
	}
}

void SceneManager::SetDefaultSceneNames(List<String> defaultSceneNames)
{
	for (auto& sceneName : defaultSceneNames)
	{
		m_DefaultSceneNames.push_back(sceneName);
	}
}

void SceneManager::LoadScenes(List<String> sceneNames)
{
	for (auto sceneName : sceneNames)
	{
		auto* scene = m_SceneStorage[sceneName];
		m_InitializeScenesQueue.push(scene);
	}
}

void SceneManager::PreloadSceneResources(List<String> sceneNames)
{
	// Put it in a thread
	for (auto sceneName : sceneNames)
	{
		auto* scene = m_SceneStorage[sceneName];
		scene->LoadResources();
	}
}

void SceneManager::LoadDefaultScenes()
{
	LoadScenes(m_DefaultSceneNames);
}

void SceneManager::InitializeScenes()
{
	while (!m_InitializeScenesQueue.empty())
	{
		auto* scene = m_InitializeScenesQueue.front();
		scene->LoadResources();
		scene->CreateEntities();
		scene->Initialize();
		m_ActiveScenes.emplace_back(scene);
		m_InitializeScenesQueue.pop();
	}
}

void SceneManager::DeinitializeScenes()
{
	while (!m_DeinitializeScenesQueue.empty())
	{
		auto* scene = m_DeinitializeScenesQueue.front();
		scene->Deinitialize();
		scene->DestroyEntities();
		scene->UnloadResources();
		m_DeinitializeScenesQueue.pop();
	}
}

void SceneManager::UnloadActiveScenes()
{
	for (auto* scene : m_ActiveScenes)
	{
		m_DeinitializeScenesQueue.push(scene);
	}
	m_ActiveScenes.clear();
	m_ActiveScenes.shrink_to_fit();
}

bool SceneManager::IsSceneActive(StringRef sceneName) const
{
	auto findSceneFunc = [sceneName](AScene* other) -> bool
	{
		return other != nullptr && sceneName == other->GetName();
	};
	const auto foundScene = std::ranges::find_if(m_ActiveScenes,
	                                             findSceneFunc);
	return foundScene != m_ActiveScenes.end();
}

const List<AScene*>& SceneManager::GetActiveScenes() const
{
	return m_ActiveScenes;
}
