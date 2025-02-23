#pragma once
#include <random>
#include <ctime>
#include <SFML/Graphics.hpp>
struct  Vec2
{
    Vec2(float x_ = 0, float y_ = 0);

    float x;
    float y;
};
struct AABB
{
    AABB(Vec2 Amin_, Vec2 Amax);
    Vec2 Amin;
    Vec2 Amax;
};
class Randomnumber
{
public:
    int getrandomnumber(int min, int max);
};

class RandomSpawn
{

public:
    RandomSpawn(Vec2 Min, Vec2 Max);
    sf::Vector2f m_spawnCordonate();

private:
    Randomnumber m_rand;
    Vec2 m_Min;
    Vec2 m_Max;
};