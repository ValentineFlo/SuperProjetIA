#include "OptionMenu.h"
#include <SFML/Audio.hpp>

OptionMenu::OptionMenu(sf::RenderWindow* window, const float& framerate) : SceneBase(window, framerate), m_Background(sf::Vector2f(m_renderwindow->getSize()))
{
	m_Background.setTexture(&m_texture.getTexture("resource\\galaxie2.bmp"));
	init();
}

OptionMenu::~OptionMenu()
{
	for (auto Object : m_allGameObject)
		delete Object;
}

void OptionMenu::init()
{
	titleOptionWidgetInit();
	resolutionWidgetInit();
	controlsWidgetInit();
	backWidgetInit();
}

void OptionMenu::processInput(sf::Event& event)
{
	setsceneidx(2);
	if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
	{
		sf::Vector2f mousePos = m_renderwindow->mapPixelToCoords({ event.mouseButton.x, event.mouseButton.y });

		for (auto Object : m_allGameObject)
		{
			OptionMenuinput(static_cast<Widget*>(Object), mousePos);
		}
	}
}

void OptionMenu::update(const float& deltaTime)
{
	addObject();
	for (auto Object : m_allGameObject)
	{
		Object->update(deltaTime);
	}
	deleteObject();

}

void OptionMenu::OptionMenuinput(Widget* object, sf::Vector2f mousepos)
{
	if (mousepos.x > object->GetBoundingBox().Amin.x && mousepos.x  < object->GetBoundingBox().Amax.x
		&& mousepos.y >object->GetBoundingBox().Amin.y && mousepos.y < object->GetBoundingBox().Amax.y)
	{
		if (object->getwidgettype() == Back_Widget)
			setsceneidx(0);

	}
}

void OptionMenu::render()
{
	m_renderwindow->draw(m_Background);
	for (auto Object : m_allGameObject)
	{
		Object->render();
	}
}

void OptionMenu::setsceneidx(int idx)
{
	m_sceneidx = idx;
}

int& OptionMenu::getceneidx()
{
	return m_sceneidx;
}

void OptionMenu::titleOptionWidgetInit()
{
	Vec2 widgetControlsPos = { static_cast<float>(m_renderwindow->getSize().x / 2),0 + 100 };
	Vec2 sizeOfControls = { 800, 120 };
	auto optionTitle = new Rectanglewidget(*this, widgetControlsPos, sizeOfControls, "Options", Title_Widget);
	optionTitle->settextSize(45);
	optionTitle->setTextPosition({ widgetControlsPos.x - 130, widgetControlsPos.y - 25 });
	optionTitle->setcolor(sf::Color(sf::Color::Magenta));
	optionTitle->setTexture("resource\\etiquette.png");
	optionTitle->setFont("resource\\font\\static\\TMT-Paint-Regular.otf");
	optionTitle->GetBoundingBox();
}

void OptionMenu::resolutionWidgetInit()
{
	Vec2 widgetResolutionPos = { static_cast<float>(m_renderwindow->getSize().x / 2),0 + 350 };
	Vec2 sizeOfResolution = { 450, 155 };
	auto resolutiontext = new Rectanglewidget(*this, widgetResolutionPos, sizeOfResolution, "Resolution", Resolution_Widget);
	resolutiontext->settextSize(45);
	resolutiontext->setTextPosition({ widgetResolutionPos.x - 160, widgetResolutionPos.y - 25 });
	resolutiontext->setcolor(sf::Color(sf::Color::Blue));
	resolutiontext->setTexture("resource\\etiquette.png");
	resolutiontext->setFont("resource\\font\\static\\TMT-Paint-Regular.otf");
	resolutiontext->GetBoundingBox();
}

void OptionMenu::controlsWidgetInit()
{
	Vec2 widgetControlsPos = { static_cast<float>(m_renderwindow->getSize().x / 2),0 + 600 };
	Vec2 sizeOfControls = { 450, 155 };
	auto controltext = new Rectanglewidget(*this, widgetControlsPos, sizeOfControls, "Controls", Control_Widget);
	controltext->settextSize(45);
	controltext->setTextPosition({ widgetControlsPos.x - 130, widgetControlsPos.y - 25 });
	controltext->setcolor(sf::Color(sf::Color::Blue));
	controltext->setTexture("resource\\etiquette.png");
	controltext->setFont("resource\\font\\static\\TMT-Paint-Regular.otf");
	controltext->GetBoundingBox();
}

void OptionMenu::backWidgetInit()
{
	Vec2 widgetBackPos = { static_cast<float>(m_renderwindow->getSize().x / 2),0 + 850 };
	Vec2 sizeOfBack = { 450, 155 };
	auto backText = new Rectanglewidget(*this, widgetBackPos, sizeOfBack, "Back", Back_Widget);
	backText->settextSize(45);
	backText->setTextPosition({ widgetBackPos.x - 55, widgetBackPos.y - 25 });
	backText->setcolor(sf::Color(sf::Color::Blue));
	backText->setTexture("resource\\etiquette.png");
	backText->setFont("resource\\font\\static\\TMT-Paint-Regular.otf");
	backText->GetBoundingBox();
}