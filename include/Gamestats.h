#pragma once
#include <SFML/Graphics.hpp>
#include "Text.h"

const enum stats { Time, Lvl, Key, Charector };

class Gamestats
{
public:
	Gamestats(const sf::Font& font);
	void setstring(std::string str, int data, stats kind);
	void changeColor(const sf::Color& color, stats kind);
	void draw(sf::RenderWindow& window) const;

private:
	Text m_time;
	Text m_level;
	Text m_key;
	Text m_charector;
};

