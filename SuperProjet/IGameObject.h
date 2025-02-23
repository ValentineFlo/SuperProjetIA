#pragma once
#include <SFML/Graphics.hpp>
#include "MyMaths.h"
class Game;
class SceneBase;
enum  GameOvject
{
    Type_Ship = 0
    , Type_Ennemie_Ship = 1
    , Type_Missile = 2
    , Type_Ennemie_Missile = 3
    , Type_Barrier = 4
    , Type_Barrier_Only_Misssile = 5
    , Type_Asteroid = 6
    , Type_Commette = 7
    , Type_RectangleWidget = 8
    , Type_RectangleWidgetupdatable = 9
    , Type_Live = 10
    , Type_BossFox = 11
    , Type_FoxMissille = 12
    , Type_Carrotboss = 13
    , Type_CarroteMissile = 14
    , Type_LuminuxBoss = 15
    , Type_LuminuxMissile = 16
};

enum BarrierPosition
{
    Position_Left = 0
    , Position_Right = 1
    , Position_Top = 2
    , Position_Botom = 3

};

class IGameObject
{
public:

    virtual ~IGameObject();
    IGameObject(SceneBase& game);
    virtual void input(sf::Event event) = 0;
    virtual void update(float deltatime) = 0;
    virtual void render() = 0;
    virtual int& gettype() = 0;
    virtual AABB GetBoundingBox() = 0;
    virtual void TakeDomage(int num = 1, int score = 0) = 0;

    int& getVie() { return m_vie; }

protected:
    SceneBase& m_game;
    Randomnumber* m_rand;
    RandomSpawn* m_randPosition;
    int m_score;
    int m_vie;
    Vec2 Amin;
    Vec2 Amax;
    int m_type;
    sf::Clock m_takedomage;
    sf::Time m_timetotakedomage;
};

