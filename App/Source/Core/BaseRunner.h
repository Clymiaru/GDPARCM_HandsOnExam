#pragma once
#include <SFML/Graphics.hpp>

#include "SceneManagement/AScene.h"
#include "Event/Event.h"
#include "Utils/TypeAlias.h"

struct Resolution
{
	Uint Width;
	Uint Height;
};

class BaseRunner final
{
public:
	static Resolution WindowSize;

	BaseRunner(Resolution windowSize,
               StringRef title,
               List<AScene*> availableScenes,
               StringRef startingSceneName);
	~BaseRunner();
	
	void Run();

private:
	sf::Event m_Event;
	sf::RenderWindow m_Window;
	String m_DefaultSceneName;
	float m_Ticks = 0.0f;
	bool m_IsRunning = false;
	Queue<Event*> m_EventQueue;

	void Initialize();
	void ProcessEvents();
	void Update(float deltaTime);
	void Render();
	void Deinitialize();
};
