#pragma once
#include <SFML/Graphics.hpp>

#include "IconCodex.h"
#include "IconDeleter.h"
#include "IconSearcher.h"

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
               StringRef title);
	~BaseRunner();
	
	void Run();

private:
	sf::Event m_Event;
	sf::RenderWindow m_Window;
	float m_Ticks = 0.0f;
	bool m_IsRunning = false;
	
	IconCodex* m_IconCodex;
	List<IconSearcher*> m_IconSearchers;
	List<IconDeleter*> m_IconDeleters;
	// List<IconInserter>

	void Initialize();
	void ProcessEvents();
	void Update(float deltaTime);
	void Render();
	void Deinitialize();
};
