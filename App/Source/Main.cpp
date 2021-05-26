#include "pch.h"
#include "Core/BaseRunner.h"

#include "SceneManagement/Scene/Scenes.h"
#include "SceneManagement/Scene/MainScene.h"

int main()
{
	auto app = BaseRunner({1280, 720},
						  "Hands On Exam",
						  {new MainScene()},
						  Scenes::MAIN_SCENE);

	app.Run();
}
