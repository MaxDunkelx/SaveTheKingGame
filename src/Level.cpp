#include "Level.h"
#include <iostream>
Level::Level():m_levelTime(),m_squreAmount(),m_level()
{
}

bool Level::loadLevel(int numOfLevel)
{
	char NAME_FILE[] = "board#.txt";
	NAME_FILE[5] = numOfLevel + '0';//change the text file number, every new load
									//each new level goes up in the number to the next 
	m_file.open(NAME_FILE, std::ios::in);

	if (!m_file.is_open())
		return false; //when there are no new levels file

	m_file >> m_squreAmount.x >> m_squreAmount.y >> m_levelTime;
	char square;
	m_file.get(square);//skip first '\n'
	for (unsigned int i = 0; i < m_squreAmount.y; ++i)
	{
		std::vector<char> Ctemp;
		for (unsigned int j = 0; j < m_squreAmount.x; ++j)
		{
			m_file.get(square);
			if (square == 'k')//king
			{
				Ctemp.push_back('k');
	
			}
			else if (square == 'm')//mage
			{
				Ctemp.push_back('m');
			}
			else if (square == 'w')//warrior
			{
				Ctemp.push_back('w');
				
			}
			else if (square == 't')//thief
			{
				Ctemp.push_back('t');
			}
			else if (square == '!')//orc
			{
				Ctemp.push_back('!');
			}
			else if (square == '^')//dwarf
			{
				Ctemp.push_back('^');
			}
			else if (square == '*')//fire
			{
				Ctemp.push_back('*');
			}
			else if (square == '#')//gate
			{
				Ctemp.push_back('#');
			}
			else if (square == '=')//wall
			{
				Ctemp.push_back('=');
			}
			
			else if (square == 'x')//teleport
			{
				Ctemp.push_back('x');
			}
			else if (square == '$')//gift
			{
				Ctemp.push_back('$');
			}
			else if (square == 'f')//key and dragon
			{
				Ctemp.push_back('f');
			}
			else if (square == '^')//key
			{
				Ctemp.push_back('^');
			}
			else if (square == '!')//key
			{
				Ctemp.push_back('!');
			}
			else if (square == '@')//key
			{
				Ctemp.push_back('@');
			}
			
			else
			{
				Ctemp.push_back(' ');
			}
		}
		m_level.push_back(Ctemp);
		m_file.get(square);//skip first '\n'
	}
	m_file.close();
	return true;
}

int Level::getLevelTime() const
{

	return m_levelTime;
}

char Level::operator()(unsigned int row,unsigned  int col) const
{
	return m_level[row][col];
}

void Level::clear()
{
	m_level.clear();
}

const sf::Vector2u& Level::getNumOfSquares() const
{
	return m_squreAmount;
}


