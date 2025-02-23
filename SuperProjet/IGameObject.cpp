#include "IGameObject.h"
#include "Game.h"
#include "SceneBase.h"

IGameObject::~IGameObject()
{


}

IGameObject::IGameObject(SceneBase& game) : m_game(game), m_score(0)
{
	m_game.m_tobeaddGameObject.push_back(this);

}
