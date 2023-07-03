#pragma once
#include "Board.h"
#include"Menu.h"
#include "Music.h"
#include <SFML/Graphics.hpp>
#include <vector>
#include"Gamestats.h"


class Controller {

public:
	Controller();

	void run();
	void runMenu();
	void runFinalMenu();
	void runHelp();




private:
	
	bool isLvlComplete();
	Board m_board;
	Menu m_menu;
	Text m_press;
	sf::Sound m_backgroundSound;
	unsigned int m_numOfLevel;
	sf::Sprite m_background;
	sf::RenderWindow m_window;
	sf::Clock m_clock;
	Gamestats m_gamestats;
	void setGameStats();
	Textures& m_textures;
	void waitUntilKeyPress();
	bool isKeyPressed();
	void setPress(sf::RenderWindow&);
	void setPressHelpMenu(sf::RenderWindow&);
};