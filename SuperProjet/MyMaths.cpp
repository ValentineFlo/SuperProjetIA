#include "MyMaths.h"
#include <cmath>

int Randomnumber::getrandomnumber(int min, int max)
{
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> dis(min, max);
	return dis(gen);
}

Vec2::Vec2(float x_, float y_) : x(x_), y(y_) {}

AABB::AABB(Vec2 Amin_, Vec2 Amax) : Amin(Amin_), Amax(Amax) {}

sf::Vector2f RandomSpawn::m_spawnCordonate()
{
	sf::Vector2f position;

	int random_border = m_rand.getrandomnumber(0, 3);
	int rabdom_Window_x = m_rand.getrandomnumber(m_Min.x, m_Max.x);
	int rabdom_Window_y = m_rand.getrandomnumber(m_Min.y, m_Max.y);
	switch (random_border)
	{
	case 0:
		position.x = m_Min.x;
		position.y = rabdom_Window_y;
		return position;
		break;
	case 1:
		position.x = rabdom_Window_x;
		position.y = m_Min.y;
		return position;
		break;
	case 2:
		position.x = m_Max.x;
		position.y = rabdom_Window_y;
		return position;
		break;
	case 3:
		position.x = rabdom_Window_x;
		position.y = m_Max.y;
		return position;
		break;
	default:
		break;
	}


}

RandomSpawn::RandomSpawn(Vec2 Min, Vec2 Max) : m_Min(Min), m_Max(Max)
{

}
