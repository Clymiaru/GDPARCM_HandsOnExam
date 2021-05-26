#pragma once
#include "AScene.h"

#include "Threading/Thread/ThreadPool.h"

class SceneManager final
{
public:
	SceneManager(const SceneManager& other)                = delete;
	SceneManager(SceneManager&& other) noexcept            = delete;
	SceneManager& operator=(const SceneManager& other)     = delete;
	SceneManager& operator=(SceneManager&& other) noexcept = delete;

	static SceneManager& GetInstance();
	~SceneManager();
	
	void RegisterScenes(List<AScene*> scenes);

	void LoadScenes(List<String> sceneNames);
	void PreloadSceneResources(List<String> sceneNames);

	void SetDefaultSceneNames(List<String> defaultSceneNames);
	void LoadDefaultScenes();
	
	void InitializeScenes(); 
	void DeinitializeScenes();
	
	void UnloadActiveScenes();
	
	bool IsSceneActive(StringRef sceneName) const;
	const List<AScene*>& GetActiveScenes() const;

private:
	SceneManager();
	
	List<String> m_DefaultSceneNames;
	List<AScene*> m_ActiveScenes;
	HashTable<String, AScene*> m_SceneStorage;
	
	Queue<AScene*> m_InitializeScenesQueue;
	Queue<AScene*> m_DeinitializeScenesQueue;
};
