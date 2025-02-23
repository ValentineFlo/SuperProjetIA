#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include "SceneBase.h"
#include "IGameObject.h"
#include "PlayableGameObject.h"
#include "Input.h"
#include "MyMaths.h"
#include "WidgetGameObject.h"

class Menu : public SceneBase
{
public:

    Menu(sf::RenderWindow* window, const float& framerate);
    ~Menu();
    void init();
    void processInput(sf::Event& event);

    void update(const float& deltaTime);

    void render()override;
    void setsceneidx(int idx);
    int& getceneidx();
    void Menuinput(Widget* object, sf::Vector2f mousepos);
    void playWidgetInit();
    void titleWidgetInit();
    void optionWidgetInit();
    void highscoreWidgetInit();
    void quitWidgetInit();

    void SoundInit();
    void MusicInit();

private:
    sf::Music* menuMusic;
    //sf::SoundBuffer hoverBuffer;
    //sf::SoundBuffer clickBuffer;
    //sf::Sound hoverSound;
    //sf::Sound clickSound;
};
