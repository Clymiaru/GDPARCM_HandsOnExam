#include "pch.h"
#include "BaseRunner.h"

#include "AssetManagement/AssetManager.h"
#include "AssetManagement/Texture/Textures.h"
#include "AssetManagement/Texture/Texture.h"
#include "Utils/Random.h"
Resolution BaseRunner::WindowSize;

BaseRunner::BaseRunner(Resolution windowSize,
					   StringRef title) :
	m_Event{},
	m_IconCodex{nullptr},
	m_SharedData{nullptr},
	m_IconSearchers{},
	m_IconInserters{},
	m_IconDeleters{}
{
	WindowSize        = std::move(windowSize);
	const auto width  = WindowSize.Width;
	const auto height = WindowSize.Height;
	m_Window.create(sf::VideoMode(width, height),
	                title,
	                sf::Style::Close);
	m_Window.setFramerateLimit(30);
	m_IsRunning = m_Window.isOpen();
}

BaseRunner::~BaseRunner()
{
}

void BaseRunner::Run()
{
	Initialize();

	sf::Clock clock;
	while (m_IsRunning)
	{
		const auto dt = clock.restart();
		ProcessEvents();
		Update(dt.asSeconds());
		Render();
		Deinitialize();
	}
}

void BaseRunner::Initialize()
{
	auto& assetManager = AssetManager::GetInstance();
	assetManager.Load<Texture>(TextureNames::REI_ICON, TextureFilepaths::REI_ICON);
	assetManager.Load<Texture>(TextureNames::YUI_ICON, TextureFilepaths::YUI_ICON);
	assetManager.Load<Texture>(TextureNames::MIMI_ICON, TextureFilepaths::MIMI_ICON);
	assetManager.Load<Texture>(TextureNames::RIMA_ICON, TextureFilepaths::RIMA_ICON);
	assetManager.Load<Texture>(TextureNames::HIYORI_ICON, TextureFilepaths::HIYORI_ICON);
	assetManager.Load<Texture>(TextureNames::KYOUKA_ICON, TextureFilepaths::KYOUKA_ICON);
	assetManager.Load<Texture>(TextureNames::MISOGI_ICON, TextureFilepaths::MISOGI_ICON);
	assetManager.Load<Texture>(TextureNames::SHIORI_ICON, TextureFilepaths::SHIORI_ICON);
	assetManager.Load<Texture>(TextureNames::RANGER_RIN_ICON, TextureFilepaths::RANGER_RIN_ICON);
	assetManager.Load<Texture>(TextureNames::RANGER_MAHIRU_ICON, TextureFilepaths::RANGER_MAHIRU_ICON);
	assetManager.Load<Texture>(TextureNames::AKARI_ICON, TextureFilepaths::AKARI_ICON);
	assetManager.Load<Texture>(TextureNames::ANNE_ICON, TextureFilepaths::ANNE_ICON);
	assetManager.Load<Texture>(TextureNames::LUNA_ICON, TextureFilepaths::LUNA_ICON);
	assetManager.Load<Texture>(TextureNames::MAHO_ICON, TextureFilepaths::MAHO_ICON);
	assetManager.Load<Texture>(TextureNames::MUIMI_ICON, TextureFilepaths::MUIMI_ICON);
	assetManager.Load<Texture>(TextureNames::NENEKA_ICON, TextureFilepaths::NENEKA_ICON);
	assetManager.Load<Texture>(TextureNames::RINO_ICON, TextureFilepaths::RINO_ICON);
	assetManager.Load<Texture>(TextureNames::SUZUNA_ICON, TextureFilepaths::SUZUNA_ICON);
	assetManager.Load<Texture>(TextureNames::TAMAKI_ICON, TextureFilepaths::TAMAKI_ICON);
	assetManager.Load<Texture>(TextureNames::YUKARI_ICON, TextureFilepaths::YUKARI_ICON);

	assetManager.Load<Texture>(TextureNames::SELECTER_ARROW, TextureFilepaths::SELECTER_ARROW);
	assetManager.Load<Texture>(TextureNames::DELETER_ARROW, TextureFilepaths::DELETER_ARROW);
	assetManager.Load<Texture>(TextureNames::INSERTER_ARROW, TextureFilepaths::INSERTER_ARROW);

	List<Texture*> assetIcons;
	assetIcons.emplace_back(&assetManager.Acquire<Texture>(TextureNames::REI_ICON));
	assetIcons.emplace_back(&assetManager.Acquire<Texture>(TextureNames::YUI_ICON));
	assetIcons.emplace_back(&assetManager.Acquire<Texture>(TextureNames::MIMI_ICON));
	assetIcons.emplace_back(&assetManager.Acquire<Texture>(TextureNames::RIMA_ICON));
	assetIcons.emplace_back(&assetManager.Acquire<Texture>(TextureNames::HIYORI_ICON));
	assetIcons.emplace_back(&assetManager.Acquire<Texture>(TextureNames::KYOUKA_ICON));
	assetIcons.emplace_back(&assetManager.Acquire<Texture>(TextureNames::MISOGI_ICON));
	assetIcons.emplace_back(&assetManager.Acquire<Texture>(TextureNames::SHIORI_ICON));
	assetIcons.emplace_back(&assetManager.Acquire<Texture>(TextureNames::RANGER_RIN_ICON));
	assetIcons.emplace_back(&assetManager.Acquire<Texture>(TextureNames::RANGER_MAHIRU_ICON));
	assetIcons.emplace_back(&assetManager.Acquire<Texture>(TextureNames::AKARI_ICON));
	assetIcons.emplace_back(&assetManager.Acquire<Texture>(TextureNames::ANNE_ICON));
	assetIcons.emplace_back(&assetManager.Acquire<Texture>(TextureNames::LUNA_ICON));
	assetIcons.emplace_back(&assetManager.Acquire<Texture>(TextureNames::MAHO_ICON));
	assetIcons.emplace_back(&assetManager.Acquire<Texture>(TextureNames::MUIMI_ICON));
	assetIcons.emplace_back(&assetManager.Acquire<Texture>(TextureNames::NENEKA_ICON));
	assetIcons.emplace_back(&assetManager.Acquire<Texture>(TextureNames::RINO_ICON));
	assetIcons.emplace_back(&assetManager.Acquire<Texture>(TextureNames::SUZUNA_ICON));
	assetIcons.emplace_back(&assetManager.Acquire<Texture>(TextureNames::TAMAKI_ICON));
	assetIcons.emplace_back(&assetManager.Acquire<Texture>(TextureNames::YUKARI_ICON));
	
	auto& selectorTex = assetManager.Acquire<Texture>(TextureNames::SELECTER_ARROW);
	auto& deleterTex = assetManager.Acquire<Texture>(TextureNames::DELETER_ARROW);
	auto& inserterTex = assetManager.Acquire<Texture>(TextureNames::INSERTER_ARROW);
	
	m_IconCodex = new IconCodex(assetIcons, {100.0f, 100.0f});
	m_IconCodex->ShowIcons(10);

	for (int i = 0; i < MAX_ACTIVE_ICON_COUNT; i++)
	{
		m_Lines[i] = sf::RectangleShape({4.0f, 720.0f});
		m_Lines[i].setOrigin(4.0f / 2.0f, 720.0f / 2.0f);
		m_Lines[i].setPosition({75.0f + (100.0f + 25.0f) * i, 720.0f / 2});
		m_Lines[i].setFillColor(sf::Color(255, 255, 255, 40));
	}
	
	m_SharedData = new SharedIconCodexData(m_IconCodex);


	for (auto i = 0; i < NUM_OF_SEARCHERS; i++)
	{
		m_IconSearchers[i] = new IconSearcher(selectorTex,*m_SharedData, i + 1 );
		m_IconSearchers[i]->Start();
	}

	for (auto i = 0; i < NUM_OF_DELETERS; i++)
	{
		m_IconDeleters[i] = new IconDeleter(deleterTex,*m_SharedData);
		m_IconDeleters[i]->Start();
	}
	
	for (auto i = 0; i < NUM_OF_INSERTERS; i++)
	{
		m_IconInserters[i] = new IconInserter(inserterTex,*m_SharedData);
		m_IconInserters[i]->Start();
	}
}

void BaseRunner::ProcessEvents()
{
	sf::Event event;
	while (m_Window.pollEvent(event))
	{
		switch (event.type)
		{
			case sf::Event::Closed:
				m_IsRunning = false;
				break;
			default:
				break;
		}
	}
}

void BaseRunner::Update(const float deltaTime)
{
}

void BaseRunner::Render()
{
	m_Window.clear();

	for (auto& line : m_Lines)
	{
		m_Window.draw(line);
	}

	m_IconCodex->DrawIcons(m_Window);

	

	for (auto& searcher : m_IconSearchers)
	{
		searcher->Draw(m_Window);
	}

	for (auto& deleter : m_IconDeleters)
	{
		deleter->Draw(m_Window);
	}
	
	for (auto& inserter : m_IconInserters)
	{
		inserter->Draw(m_Window);
	}
	m_Window.display();
}

void BaseRunner::Deinitialize()
{
	if (m_IsRunning == false)
	{
		m_Window.close();
	}
}
