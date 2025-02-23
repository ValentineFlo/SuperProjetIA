#include "SceneBase.h"
#include "Scenemanager.h"
SceneBase::SceneBase(sf::RenderWindow* window, const float& framerate) :
	m_renderwindow(window)
	, m_refreshTime(sf::seconds(1.f / framerate))
	, m_totalscore(0)

{ }

sf::Time SceneBase::getRefreshTime() const
{
	return m_refreshTime;
}

TextureCache& SceneBase::gettexture()
{
	return m_texture;
}

FontCache& SceneBase::getfont()
{
	return m_font;
}
void SceneBase::addObject()
{
	for (auto toaddgameobject : m_tobeaddGameObject)
		m_allGameObject.push_back(toaddgameobject);
	m_tobeaddGameObject.clear();
}

void SceneBase::toberemoved(IGameObject* it)
{
	m_toberemovedGameObject.push_back(it);
}




void SceneBase::deleteObject()
{

	for (auto it = m_toberemovedGameObject.begin(); it != m_toberemovedGameObject.end(); )
	{
		auto gameObjIt = std::find(m_allGameObject.begin(), m_allGameObject.end(), *it);
		if (gameObjIt != m_allGameObject.end())
		{
			delete* gameObjIt;
			m_allGameObject.erase(gameObjIt);
			it = m_toberemovedGameObject.erase(it);
		}
		else
		{
			++it;
		}
	}
}
void SceneBase::addScore(int score)
{
	m_totalscore += score;
}
sf::Vector2u SceneBase::getWindowSize()
{
	return m_renderwindow->getSize();
}

sf::RenderWindow* SceneBase::getWindow()
{
	return m_renderwindow;
}
