#include "MyGame.h"
#include "Scenemanager.h"

inline myGame::myGame(SceneManager& scene) : m_scene(scene) {}

void myGame::Exe()
{
	m_scene.Exe();
}
