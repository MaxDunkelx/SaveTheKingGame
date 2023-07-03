#pragma once
#include <SFML/Graphics.hpp>
#include "Textures.h"
#include "macros.h"


const sf::Vector2f BACKGROUNDSIZE(1200, 800);
const sf::Vector2f BUTTON_SIZE(180, 100);
enum  Button { Start, Exit, Help ,Nothing };


class Menu {
public:
	Menu();
	void handleMouse(const sf::Vector2f& location);
	void draw(sf::RenderWindow& window) const;//draw the open screen
	void drawFinal(sf::RenderWindow& window) const;//draw the final(game over) screen
	void drawHelp(sf::RenderWindow& window) const;//draw the help screen
	Button whoIsPressed(const sf::Vector2f& location);
   

private:
	sf::Sprite m_start;
	sf::Sprite m_help;
	sf::Sprite m_exit;
	sf::Sprite m_background;
	sf::Sprite m_GameOver;
	sf::Sprite m_helpMenu;
	
};