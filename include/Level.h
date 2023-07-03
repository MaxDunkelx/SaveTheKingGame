#pragma once
#include <SFML/Graphics.hpp>
#include <fstream>
#include <vector>
#include "Textures.h"
#include"Macros.h"


class Level {
public:
	Level();
	bool loadLevel(int numOfLevel);
	int getLevelTime() const;
	char operator()(unsigned int,unsigned int) const;

	void clear();
	const sf::Vector2u& getNumOfSquares() const;
	

private:
	std::ifstream m_file;
	std::vector<std::vector<char>> m_level;
	sf::Vector2u m_squreAmount;
	int m_levelTime;
	
};