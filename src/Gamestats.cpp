#include <SFML/Graphics.hpp>
#include"Gamestats.h"
#include<iostream>
const sf::Vector2f startPos(200, 0);//start position of the game state data

Gamestats::Gamestats(const sf::Font& font)
	:m_level(font), m_time(font), m_key(font), m_charector(font)
{
	m_level.setPosition(sf::Vector2f(startPos.x, startPos.y));
	m_time.setPosition(sf::Vector2f(startPos.x * 2, startPos.y));
	m_key.setPosition(sf::Vector2f(startPos.x * 3, startPos.y));
	m_charector.setPosition(sf::Vector2f(startPos.x * 4 , startPos.y));
	
}//end game stats

void Gamestats::setstring(std::string str, int data, stats kind)
{
	switch (kind)
	{
	case Time:
		if (data != -1)//if level is unlimited - don't print the time (int) data
			str.append(std::to_string(data));//attach int data to the string
		m_time.setText(str);
		break;

	case Lvl:
		str.append(std::to_string(data));//attach int data to the string
		m_level.setText(str);
		break;

	case Key:
		str.append(std::to_string(data));//attach int data to the string
		m_key.setText(str);
		break;

	case Charector:
		str.append(std::to_string(data));//attach int data to the string
		m_charector.setText(str);
		break;
	}
}//end setstring

void Gamestats::changeColor(const sf::Color& color, stats kind)
{
	switch (kind)
	{
	case Time:
		m_time.setcolor(color);
		break;

	case Lvl:
		m_level.setcolor(color);
		break;

	case Key:
		m_key.setcolor(color);
		break;

	case Charector:
		m_charector.setcolor(color);
		break;
	}
}//end changeColor

void Gamestats::draw(sf::RenderWindow& window) const
{
	m_time.draw(window);
	m_level.draw(window);
	m_key.draw(window);
	m_charector.draw(window);
}//end draw
