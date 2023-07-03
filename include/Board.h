#pragma once
#include <SFML/Graphics.hpp>
#include <fstream>
#include <ctime>
#include <vector>
#include "Textures.h"
#include"Level.h"
#include "StaticObjects.h"
#include "macros.h"
#include <cstdlib>
#include <string>
#include "Text.h"

//charectors
#include "King.h" 
#include "Mage.h" 
#include "Warrior.h" 
#include"Thief.h"
#include"Dwarf.h"
#include"Orc.h"

//static objects
#include"Gate.h"
#include "Fire.h"
#include"Wall.h"
#include"Teleport.h"
#include"Throne.h"
#include"Gifts.h"
#include"Throne.h"
#include"Key.h"






class Board {

public:
	Board();
	bool loadLvl(int lvlnumber);
	void draw(sf::RenderWindow&);
	void move(const sf::Time& time);
	void nextCharector();
	void updateTime();
	bool isLevelFinished();
	void handleGift();
	void dwarfManeger(bool );
	void clearVectors();
	void teleport();
	void restartLvl();
	int getLevelTime();
	int currentCharector();
	bool holdingKey();
	void pushMes(sf::Clock &,sf::RenderWindow&);

private:
	//the time private variables
	sf::Clock m_clock;
	int m_levelTime;

	unsigned int m_current_char;//current charector moving
	Text m_mes;

	//the game object vectors
	std::vector <std::unique_ptr<Movable>> m_moveable;
	std::vector <std::vector<std::unique_ptr<StaticObjects>>> m_static;
	std::vector<sf::Vector2f> m_teleport;
	sf::Sprite createSprite(GameObjects type, int col, int row);


	//level loading variables
	Level m_level;
	sf::Vector2f m_size;

	//collision detection between all game variables 
	void m_charector2Charector();
	void m_charector2Enemy();
	void m_enemy2Enemy();
	void movable2Static();






};