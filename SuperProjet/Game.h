#pragma once
#include <SFML/Graphics.hpp>
#include "SceneBase.h"
#include "IGameObject.h"
#include "MyMaths.h"
#include <array>

class Rectanglewidgetupdatable;
class Rectanglewidget;
class GameInput;
class Ship;
class Barrier;
class Iinput;


class Game : public SceneBase
{
public:
    friend GameInput;

    Game(sf::RenderWindow* window, const float& framereta);
    ~Game();
    void processInput(sf::Event& event);
    void objectinput(sf::Event& event);
    void update(const float& deltaTime);
    void setsceneidx(int idx);
    int& getceneidx();
    void render();
    void init();
    void testColision(IGameObject* A, IGameObject* B);
    bool colision(AABB A, AABB B);

    void findValidTarget();

    //window 

    void spawnObject();
    void bossspawn();
    void renderAABB();

public:
    std::array<IGameObject*, 3> m_bosses;

private:


    bool m_bossevent;
    int m_bosscount;
    int m_bossfactor;
    IGameObject* currentboss;

    Ship* m_player;
    bool m_showAABB = false;
    Iinput* m_input;
    float m_Borderlimit;
    Randomnumber m_rand;
    sf::Clock m_spawn;
    sf::Time m_spawntime;
    int m_scorebase;
    Rectanglewidgetupdatable* tmps;
};
