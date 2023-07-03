#pragma once
#include <SFML/Graphics.hpp>


class Text {
public:
	Text(const sf::Font& font);
	void draw(sf::RenderWindow& window) const ;
	void setcolor(const sf::Color& color);
	void setText(std::string str);
	void setPosition(const sf::Vector2f& location);
	void setCharSize(int size);

private:
	sf::Text m_text;
};