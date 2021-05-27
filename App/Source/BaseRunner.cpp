#include "pch.h"
#include "BaseRunner.h"

#include "AssetManagement/AssetManager.h"
#include "AssetManagement/Texture/Textures.h"
#include "AssetManagement/Texture/Texture.h"
#include "Utils/Random.h"
Resolution BaseRunner::WindowSize;

BaseRunner::BaseRunner(Resolution windowSize,
					   StringRef title) :
	m_Event{}
{
	WindowSize        = std::move(windowSize);
	const auto width  = WindowSize.Width;
	const auto height = WindowSize.Height;
	m_Window.create(sf::VideoMode(width, height),
                    title,
                    sf::Style::Close);

	m_Window.setFramerateLimit(60);
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
	
	auto& selectorTex = assetManager.Acquire<Texture>(TextureNames::SELECTER_ARROW);
	auto& deleterTex = assetManager.Acquire<Texture>(TextureNames::DELETER_ARROW);
	auto& inserterTex = assetManager.Acquire<Texture>(TextureNames::INSERTER_ARROW);
	
	m_IconCodex = new IconCodex(assetIcons, {100.0f, 100.0f});
	m_IconCodex->ShowIcons(10);

	for (auto i = 0; i < 4; i++)
	{
		m_IconSearchers.push_back(new IconSearcher(selectorTex,
												   *m_IconCodex));
		m_IconSearchers[i]->SelectNextIcon();
	}

	// for (auto i = 0; i < 1; i++)
	// {
	// 	m_IconDeleters.push_back(new IconDeleter(deleterTex,
	// 											   m_IconCodex->GetActiveIcons()));
	// }
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
	m_Ticks += deltaTime;
	static int currentIconSearcher = 0;
	
	if (m_Ticks > 0.2f)
	{
		currentIconSearcher = Utils::Random::GetInt(0, 3);
		m_IconSearchers[currentIconSearcher]->SelectNextIcon();
	
		// m_IconDeleters.front()->DeleteRandomIcon();
		m_Ticks = 0;
	}
}

void BaseRunner::Render()
{
	m_Window.clear();
	
	m_IconCodex->DrawIcons(m_Window);

	for (auto& searcher : m_IconSearchers)
	{
		searcher->Draw(m_Window);
	}

	// for (auto& deleter : m_IconDeleter)
	// {
	// 	
	// }
	//
	// for (auto& inserter : m_IconInserter)
	// {
	// 	
	// }
	
	m_Window.display();
}

void BaseRunner::Deinitialize()
{
	if (m_IsRunning == false)
	{
		m_Window.close();
	}
}
