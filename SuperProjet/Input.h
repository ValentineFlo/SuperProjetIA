#pragma once
#include <SFML/Graphics.hpp>
#include "PlayableGameObject.h"
#include "IGameObject.h"
enum AI_move
{
	Move_Right
	, Move_Left
	, Move_Down
	, Move_Up
	, Move_Closer_Player
	, Shoot
	, Rotate
};

class Iinput
{
public:
	virtual ~Iinput() = default;
	virtual void processinput(sf::Event& event) = 0;


};


class PlayerInput : public Iinput
{
public:
	PlayerInput(IGameObject& object);
	void processinput(sf::Event& event)override;
private:
	float m_velocity;
	IGameObject& m_object;
};

class IaInput : public Iinput
{
public:

	IaInput(IGameObject& object);
	void processinput(sf::Event& event) override;
private:
	int m_actioncout;
	float m_velocity;
	int  m_random_number;
	IGameObject& m_object;
};
class  GameInput : public Iinput
{
public:
	GameInput(Game& game);
	void processinput(sf::Event& event)override;
private:
	Game& m_game;
	sf::Clock m_clock;
	sf::Time m_Time;
	float m_lag;
};
class IaBossFoxInput : public Iinput
{
public:

	IaBossFoxInput(IGameObject& object);
	void processinput(sf::Event& event) override;
private:
	int m_actioncout;
	float m_velocity;
	int  m_random_number;
	IGameObject& m_object;
};
class IaBossCarrotInput : public Iinput
{
public:

	IaBossCarrotInput(IGameObject& object);
	void processinput(sf::Event& event) override;
private:
	int m_actioncout;
	float m_velocity;
	int  m_random_number;
	IGameObject& m_object;
};
class IaBossLuminuxInput : public Iinput
{
public:

	IaBossLuminuxInput(IGameObject& object);
	void processinput(sf::Event& event) override;
private:
	int m_actioncout;
	float m_velocity;
	int  m_random_number;
	IGameObject& m_object;
};