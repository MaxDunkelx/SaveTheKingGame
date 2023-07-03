#include"Text.h"

Text::Text(const sf::Font& font)
{
	m_text.setFont(font);
}//end text constructor

void Text::draw(sf::RenderWindow& window) const 
{
	window.draw(m_text);
}//end draw

void Text::setcolor(const sf::Color& color)
{
	m_text.setColor(color);
}//end setColor

void Text::setText(std::string str)
{
	m_text.setString(str);
	m_text.setOutlineThickness(3);
	m_text.setOutlineColor(sf::Color::Blue);
}//end setText

void Text::setPosition(const sf::Vector2f& location)
{
	m_text.setPosition(location);
}//end setPosition

void Text::setCharSize(int size)//change text size
{
	m_text.setCharacterSize(size);
}//end setCharacterSize


