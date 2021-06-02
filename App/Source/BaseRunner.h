#pragma once
#include <SFML/Graphics.hpp>

#include "IconCodex.h"
#include "IconDeleter.h"
#include "IconInserter.h"
#include "IconSearcher.h"

#include "Utils/TypeAlias.h"

const int NUM_OF_SEARCHERS = 4;
const int NUM_OF_INSERTERS = 2;
const int NUM_OF_DELETERS =  1;

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
	float m_SearcherTicks = 0.0f;
	float m_DeleterTicks = 0.0f;
	float m_InserterTicks = 0.0f;
	bool m_IsRunning = false;
	
	IconCodex* m_IconCodex;
	SharedIconCodexData* m_SharedData;
	Array<IconSearcher*, NUM_OF_SEARCHERS> m_IconSearchers;
	Array<IconInserter*, NUM_OF_INSERTERS> m_IconInserters;
	Array<IconDeleter*, NUM_OF_DELETERS> m_IconDeleters;

	Array<sf::RectangleShape, MAX_ACTIVE_ICON_COUNT> m_Lines;

	void Initialize();
	void ProcessEvents();
	void Update(float deltaTime);
	void Render();
	void Deinitialize();
};
