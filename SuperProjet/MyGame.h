#pragma once

#include <iostream>
class SceneManager;

class myGame
{
public:
    myGame(SceneManager& scene);
    ~myGame() = default;
    void Exe();
private:
    SceneManager& m_scene;
};

