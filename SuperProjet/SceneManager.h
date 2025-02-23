#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "SceneBase.h"

class SceneManager
{
public:
    friend SceneBase;
    SceneManager(const int& width, const int& height, const std::string& title, const int& style = 7);
    void Exe();
    void processInput();
    void push_back(std::unique_ptr<SceneBase> scene);
    void setCurrentScene(const int& index);
    sf::RenderWindow* getWindow();


private:
    std::unique_ptr<sf::RenderWindow> m_window;
    std::vector<std::unique_ptr<SceneBase>> m_scenes;
    int m_currentsceneidx;
    SceneBase* m_currentScene;
    sf::Event m_event;
};
