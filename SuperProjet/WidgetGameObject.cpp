#include "WidgetGameObject.h"

// a elenver
#include <iostream>
Widget::Widget(SceneBase& game) : IGameObject(game), m_game(game)
{
}

Rectanglewidget::Rectanglewidget(SceneBase& game, Vec2& position, Vec2& Size, std::string texte, int typewidget) :Widget(game), m_currentposition(position), m_size(Size)
{
	m_typewidget = typewidget;
	m_textcontain = texte;
	m_text.setString(m_textcontain);
	m_type = Type_RectangleWidget;
	setrectangle();
}

void Rectanglewidget::setrectangle()
{
	// setSize Origin and Position of widget
	m_rectangle.setSize(sf::Vector2f(m_size.x, m_size.y));
	m_rectangle.setOrigin(sf::Vector2f(m_rectangle.getSize().x / 2, m_rectangle.getSize().y / 2));
	m_rectangle.setPosition(sf::Vector2f(m_currentposition.x, m_currentposition.y));
	// set default text
	m_color = sf::Color::Red;
	m_text.setPosition(m_rectangle.getPosition().x - m_rectangle.getSize().x / 2, m_rectangle.getPosition().y - m_rectangle.getSize().y / 2);
	m_text.setFillColor(m_color);
	m_text.setCharacterSize(10);
	m_text.setFont(m_game.getfont().getFont("C:\\Windows\\Fonts\\Arial.ttf"));

}

void Rectanglewidget::setFont(std::string font)
{
	m_text.setFont(m_game.getfont().getFont(font));
}

void Rectanglewidget::setText(std::string text)
{
	m_text.setString(text);
}

void Rectanglewidget::setTexture(std::string texture)
{
	m_rectangle.setTexture(&m_game.gettexture().getTexture(texture));
}

void Rectanglewidget::setcolor(sf::Color color)
{
	m_color = color;
}

void Rectanglewidget::settextSize(int txtsize)
{
	m_text.setCharacterSize(txtsize);
}

void Rectanglewidget::setTextPosition(Vec2 position)
{
	m_text.setPosition(sf::Vector2f(position.x, position.y));
}



int& Rectanglewidget::getwidgettype()
{
	return m_typewidget;
}

void Rectanglewidget::input(sf::Event event)
{
}

void Rectanglewidget::update(float deltatime)
{

	sf::Vector2i mousePos = sf::Mouse::getPosition(*m_game.getWindow());

	if (mousePos.x > this->GetBoundingBox().Amin.x && mousePos.x  < this->GetBoundingBox().Amax.x
		&& mousePos.y >this->GetBoundingBox().Amin.y && mousePos.y < this->GetBoundingBox().Amax.y)
		m_text.setFillColor(sf::Color::Yellow);
	else
		m_text.setFillColor(m_color);
}

void Rectanglewidget::render()
{
	m_game.getWindow()->draw(m_rectangle);

	m_game.getWindow()->draw(m_text);
}

int& Rectanglewidget::gettype()
{
	return m_type;
}

AABB Rectanglewidget::GetBoundingBox()
{
	Amin.x = m_rectangle.getPosition().x - m_rectangle.getSize().x / 2;
	Amin.y = m_rectangle.getPosition().y - m_rectangle.getSize().y / 2;

	Amax.x = m_rectangle.getPosition().x + m_rectangle.getSize().x / 2;
	Amax.y = m_rectangle.getPosition().y + m_rectangle.getSize().y / 2;

	AABB boundingbox(Amin, Amax);
	return boundingbox;
}

void Rectanglewidget::TakeDomage(int num, int score)
{
}



Rectanglewidgetupdatable::Rectanglewidgetupdatable(SceneBase& game, Vec2 position, Vec2 Size, std::string texte, int* value, int typewidget) :Widget(game), m_currentposition(position), m_size(Size), m_value(value)
{
	typewidget = typewidget;
	m_textcontain = texte;

	m_type = Type_RectangleWidgetupdatable;
	setrectangle();
}

void Rectanglewidgetupdatable::setrectangle()
{
	// setSize Origin and Position of widget
	m_rectangle.setSize(sf::Vector2f(m_size.x, m_size.y));
	m_rectangle.setOrigin(sf::Vector2f(m_rectangle.getSize().x / 2, m_rectangle.getSize().y / 2));
	m_rectangle.setPosition(sf::Vector2f(m_currentposition.x, m_currentposition.y));
	// set default text
	m_color = sf::Color::Red;
	m_text.setPosition(m_rectangle.getPosition().x - m_rectangle.getSize().x / 2, m_rectangle.getPosition().y - m_rectangle.getSize().y / 2);
	m_text.setFillColor(m_color);
	m_text.setCharacterSize(10);
	m_text.setFont(m_game.getfont().getFont("C:\\Windows\\Fonts\\Arial.ttf"));

}

void Rectanglewidgetupdatable::setFont(std::string font)
{
	m_text.setFont(m_game.getfont().getFont(font));
}

void Rectanglewidgetupdatable::setText(std::string text)
{
	m_text.setString(text);
}

void Rectanglewidgetupdatable::setTexture(std::string texture)
{
	m_rectangle.setTexture(&m_game.gettexture().getTexture(texture));
}

void Rectanglewidgetupdatable::setcolor(sf::Color color)
{
	m_color = color;
	m_text.setFillColor(m_color);
}

void Rectanglewidgetupdatable::settextSize(int txtsize)
{
	m_text.setCharacterSize(txtsize);
}

void Rectanglewidgetupdatable::setTextPosition(Vec2 position)
{
	m_text.setPosition(sf::Vector2f(position.x, position.y));
}



int& Rectanglewidgetupdatable::getwidgettype()
{
	return m_typewidget;
}

void Rectanglewidgetupdatable::input(sf::Event event)
{
}

void Rectanglewidgetupdatable::update(float deltatime)

{
	if (m_value == nullptr)
		m_text.setString(m_textcontain + std::to_string(0));
	else
		m_text.setString(m_textcontain + std::to_string(*m_value));
}

void Rectanglewidgetupdatable::render()
{
	m_game.getWindow()->draw(m_rectangle);

	m_game.getWindow()->draw(m_text);
}

int& Rectanglewidgetupdatable::gettype()
{
	return m_type;
}

AABB Rectanglewidgetupdatable::GetBoundingBox()
{
	Amin.x = m_rectangle.getPosition().x - m_rectangle.getSize().x / 2;
	Amin.y = m_rectangle.getPosition().y - m_rectangle.getSize().y / 2;

	Amax.x = m_rectangle.getPosition().x + m_rectangle.getSize().x / 2;
	Amax.y = m_rectangle.getPosition().y + m_rectangle.getSize().y / 2;

	AABB boundingbox(Amin, Amax);
	return boundingbox;
}

void Rectanglewidgetupdatable::TakeDomage(int num, int score)
{
}

