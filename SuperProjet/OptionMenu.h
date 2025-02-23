#pragma once
#include <SFML/Graphics.hpp>
#include "SceneBase.h"
#include "IGameObject.h"
#include "MyMaths.h"
#include "PlayableGameObject.h"
#include "Input.h"
#include "WidgetGameObject.h"

class OptionMenu : public SceneBase
{
public:

    OptionMenu(sf::RenderWindow* window, const float& framerate);
    ~OptionMenu();
    void init();
    void processInput(sf::Event& event);

    void update(const float& deltaTime);
    void OptionMenuinput(Widget* object, sf::Vector2f mousepos);
    void render()override;
    void setsceneidx(int idx);
    int& getceneidx();
    void titleOptionWidgetInit();
    void resolutionWidgetInit();
    void controlsWidgetInit();
    void backWidgetInit();

private:

    sf::RectangleShape m_Background;

};