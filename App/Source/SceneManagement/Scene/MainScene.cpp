#include "pch.h"
#include "MainScene.h"
#include "Scenes.h"

#include "AssetManagement/Font/Fonts.h"
#include "AssetManagement/Texture/Textures.h"

#include "Core/BaseRunner.h"

#include "ECS/Component/AlphaFadeTransitionComponent.h"
#include "ECS/Component/SpriteRendererComponent.h"

MainScene::MainScene() :
	AScene{Scenes::MAIN_SCENE}
{
}

MainScene::~MainScene()
{
}

void MainScene::LoadResourcesImpl()
{
	INFO_LOG(SceneSystem, GetName() << " is loading resources!")
}

void MainScene::CreateEntities()
{
}

void MainScene::Initialize()
{
	INFO_LOG(SceneSystem, GetName() << " is initializing!")
}

void MainScene::DestroyEntities()
{
}

void MainScene::UnloadResources()
{
	INFO_LOG(SceneSystem, GetName() << " is unloading resources!")
}

void MainScene::Deinitialize()
{
}
