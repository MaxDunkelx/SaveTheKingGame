#include "Board.h"
#include<iostream>
#include"cstdlib"
#include<cmath>
Board::Board():m_levelTime(),m_static(),m_current_char(0),m_mes(Textures::createTex().getFont())
{
	srand(time(NULL));//for enemy movement
	m_clock.restart();
	m_mes.setPosition(sf::Vector2f(400, 400));
	m_mes.setCharSize(20);
	m_mes.setcolor(sf::Color::White);

}

bool Board::loadLvl(int lvlnumber)
{
	if (!m_level.loadLevel(lvlnumber))
		return false;

	m_levelTime = m_level.getLevelTime();
	
	m_size.x = (float)BOARDSIZE_X / (float)m_level.getNumOfSquares().x;
	m_size.y = (float)BOARDSIZE_Y / (float)m_level.getNumOfSquares().y;

	m_moveable.push_back(std::make_unique<King>(createSprite(KING, 0, 0)));
	m_moveable.push_back(std::make_unique<Mage>(createSprite(MAGE, 0,0)));
    m_moveable.push_back(std::make_unique<Warrior>(createSprite(WARRIOR, 0,0)));
	m_moveable.push_back(std::make_unique<Thief>(createSprite(THIEF, 0, 0)));

	for (unsigned int i = 0; i < m_level.getNumOfSquares().y; ++i)
	{
		std::vector<std::unique_ptr<StaticObjects>> temp;

		for (unsigned int j = 0; j < m_level.getNumOfSquares().x; ++j)
		{

			if (m_level(i, j) == 'k')//player
			{
				m_moveable[KING]->setPosition(sf::Vector2f(j * m_size.x, i * m_size.y));
				temp.push_back(nullptr);
			}
			else if (m_level(i, j) == 'm')//mage
			{
				m_moveable[MAGE]->setPosition(sf::Vector2f(j * m_size.x, i * m_size.y));
				temp.push_back(nullptr);
			}
			else if (m_level(i, j) == 'w')//warrior
			{
				m_moveable[WARRIOR]->setPosition(sf::Vector2f(j * m_size.x, i * m_size.y));
				temp.push_back(nullptr);
			}
			else if (m_level(i, j) == 't')//thief
			{
				m_moveable[THIEF]->setPosition(sf::Vector2f(j * m_size.x, i * m_size.y));
				temp.push_back(nullptr);
			}

			else if (m_level(i, j) == '=')//wall
			{
				temp.push_back(std::make_unique<Wall>(createSprite(WALL, i, j)));

			}
			else if (m_level(i, j) == '*')//fire
			{
				temp.push_back(std::make_unique<Fire>(createSprite(FIRE, i, j)));

			}
			else if (m_level(i, j) == '#')//gate
			{
				temp.push_back(std::make_unique<Gate>(createSprite(GATE, i, j)));
			}
			else if (m_level(i, j) == '@')//throne
			{
				temp.push_back(std::make_unique<Throne>(createSprite(THRONE, i, j)));
				

			}
			else if (m_level(i, j) == '$')//gifts
			{
				temp.push_back(std::make_unique<Gifts>(createSprite(GIFT, i, j)));

			}
			else if (m_level(i, j) == 'x')//teleport
			{
				
				temp.push_back(std::make_unique<Teleport>(createSprite(TELEPORT, i, j)));
			
			}

			 else if (m_level(i, j) == 'f')//key and dragon
			{
				m_moveable.push_back(std::make_unique<Dragon>(createSprite(DRAGON, i, j)));
				temp.push_back(std::make_unique<Key>(createSprite(KEY, i, j)));	
				
			}
			 else if (m_level(i, j) == '^')//dwarf
			{
		m_moveable.push_back(std::make_unique<Dwarf>(createSprite(DWARF, i, j), dynamic_cast<King*>(m_moveable[KING].get())));
				temp.push_back(nullptr);
				
			}
			 else if (m_level(i, j) == '!')//orc
			{
				m_moveable.push_back(std::make_unique<Orc>(createSprite(ORC, i, j)));
				temp.push_back(nullptr);

			}

			else
			{
				temp.push_back(nullptr);
			}
			
		}
		m_static.push_back(std::move(temp));
	}

	return true;
}


	void Board::draw(sf::RenderWindow& window)
	{
		for (int i = 0; i < m_static.size(); ++i)//i = number of lines
			for (int j = 0; j < m_static[i].size(); ++j)//j = number of col
				if (m_static[i][j])//so it wouldn't try to print empty place 
					m_static[i][j]->draw(window);

		for (int i = 0; i < m_moveable.size(); ++i)
			m_moveable[i]->draw(window);




		
	}

void Board::move(const sf::Time& time)
{
	   
			m_moveable[m_current_char]->move(time);
			teleport();
		 	handleGift();
			for (unsigned int i = 4; i < m_moveable.size(); i++)
			{
				m_moveable[i]->move(time);
			}
			 m_charector2Charector();
			 m_charector2Enemy();
			 m_enemy2Enemy();
			 movable2Static();
}


void Board::nextCharector()
{
	m_current_char = ((m_current_char + 1) % 4);

}

void Board::updateTime()
{
	if (m_clock.getElapsedTime().asSeconds() > 1)
	{
		m_clock.restart();
		m_levelTime -= SECOND;

	
	}

}

sf::Sprite Board::createSprite(GameObjects type, int row, int col)
{

	auto sprite = sf::Sprite(Textures::createTex().getTexture(type));

	if (type == KING || type == MAGE ||type==WARRIOR ||type==THIEF )//reduce charector 
		sprite.setScale((m_size.x - 1.0f) / sprite.getLocalBounds().width,(m_size.y - 1.0f) / sprite.getLocalBounds().height);

	else
		sprite.setScale((m_size.x) / sprite.getLocalBounds().width, (m_size.y) / sprite.getLocalBounds().height);

	sprite.setPosition(col * m_size.x, row * m_size.y);
	
	if (type == TELEPORT)
		m_teleport.push_back(sprite.getPosition());
	
	return sprite;
}

void Board::m_charector2Charector()
{
	for (unsigned int i = 0; i < 4; i++)
	{
		{
			if (m_moveable[m_current_char]->collidesWith(*m_moveable[i]))
				m_moveable[i]->handleCollision(*m_moveable[m_current_char]);
		}
	}
}

void Board::m_charector2Enemy()
{
	for (unsigned int i = 4; i < m_moveable.size(); i++)
	{
		for (unsigned int j = 0; j < 4; j++)
		{
			if (m_moveable[i]->collidesWith(*m_moveable[j]) && m_moveable[i]->getExistens())
				(m_moveable[j])->handleCollision(*m_moveable[i]);
		}
	}
}

void Board::m_enemy2Enemy()
{
	for (unsigned int i = 4; i < m_moveable.size(); i++)
	{
		for (unsigned int j = 4; j < m_moveable.size(); j++)
		{
			if ((m_moveable[i])->collidesWith(*m_moveable[j]) && i!=j)
	     	m_moveable[j]->handleCollision(*m_moveable[i]);
		    
	     }
	}
}



void Board::movable2Static()
{

	for (int i = 0; i < m_static.size(); ++i)//i = number of lines
		for (int j = 0; j < m_static[i].size(); ++j)//j = number of col
		{
			if (m_static[i][j])
				if (m_moveable[m_current_char]->collidesWith(*m_static[i][j]) )
				{
					m_moveable[m_current_char]->handleCollision(*m_static[i][j]);
				}

			for (unsigned int k = 4; k < m_moveable.size(); k++)
			{
				if (m_static[i][j])
				{
					if (m_moveable[k]->collidesWith(*m_static[i][j]))
						m_moveable[k]->handleCollision(*m_static[i][j]);
				}
			}

		}
	handleGift();
	
}

bool Board::isLevelFinished()
{
	if (m_moveable[KING]->LevelFinish())
	{
		dwarfManeger(true);
		return true;

	}

	if (m_levelTime < -1)
	{
		m_levelTime = m_level.getLevelTime();
		restartLvl();
		return false;
	}
  
	return false;
}

void Board::handleGift()
{


	if (m_moveable[m_current_char]->gotGift())
	{
		m_moveable[m_current_char]->checkGift(false);
		auto kind = rand() %3 ;
		switch (kind)
		{
		case 0: {
			m_levelTime =m_levelTime-5;
			break;
		}
		case 1: {
			m_levelTime = m_levelTime + 5;
			break; }

		case 2: {
			dwarfManeger(false);
			break;
		}
			 
		}
	}
}

void Board::dwarfManeger(bool curr)
{
	for (int i = 4; i < m_moveable.size(); i++)
	{
		if (m_moveable[i]->Getindex()==DWARF)
		m_moveable[i]->setExistense(curr);

	}

}


void Board::clearVectors()
{
	m_moveable.clear();
	m_static.clear();
	m_level.clear();
	m_teleport.clear();
}

void Board::teleport()
{
	
		 for (unsigned int i = 0; i < m_teleport.size(); i++)
		 {

			 if (abs(m_moveable[m_current_char]->getPosition().x - m_teleport[i].x) < TELEPORTMARGIN
				 && abs(m_moveable[m_current_char]->getPosition().y - m_teleport[i].y) < TELEPORTMARGIN
				 &&m_current_char!=MAGE)
			 {
				 if (i % 2 == 0 && i < m_teleport.size())
				 {
					 unsigned int current1=i+1;
					 sf::Vector2f newlocation1 = m_teleport[current1];
					 newlocation1 += sf::Vector2f(0, 20);
					 m_moveable[m_current_char]->setPosition(newlocation1); 
				
				 }
				 else
					 {
						 unsigned int current2 = i-1;
						 sf::Vector2f newlocation2 = m_teleport[current2];
						 newlocation2 += sf::Vector2f(0, -20);
						 m_moveable[m_current_char]->setPosition(newlocation2);
				
					 }

			 }

		 }
	 }

void Board::restartLvl()
{
	m_moveable.clear();

	m_moveable.push_back(std::make_unique<King>(createSprite(KING, 0, 0)));
	m_moveable.push_back(std::make_unique<Mage>(createSprite(MAGE, 0, 0)));
	m_moveable.push_back(std::make_unique<Warrior>(createSprite(WARRIOR, 0, 0)));
	m_moveable.push_back(std::make_unique<Thief>(createSprite(THIEF, 0, 0)));

	for (unsigned int  i = 0; i < m_level.getNumOfSquares().y; ++i)
	
		for (unsigned int j = 0; j < m_level.getNumOfSquares().x; ++j)
		{

			if (m_level(i, j) == 'k')//king 
				m_moveable[KING]->setPosition(sf::Vector2f(j * m_size.x, i * m_size.y));
			
			else if (m_level(i, j) == 'm')//mage
			m_moveable[MAGE]->setPosition(sf::Vector2f(j * m_size.x, i * m_size.y));
			else if (m_level(i, j) == 'w')//warrior 
				m_moveable[WARRIOR]->setPosition(sf::Vector2f(j * m_size.x, i * m_size.y));
			else if (m_level(i, j) == 't')//thief 
				m_moveable[THIEF]->setPosition(sf::Vector2f(j * m_size.x, i * m_size.y));
			else if (m_level(i, j) == '^')//dwarf
				m_moveable.push_back(std::make_unique<Dwarf>(createSprite(DWARF, i, j), dynamic_cast<King*>(m_moveable[KING].get())));
			else  if (m_level(i, j) == '!')//orc
               m_moveable.push_back(std::make_unique<Orc>(createSprite(ORC, i, j)));
	     	else if (m_level(i, j) == 'f')//key and dragon
				m_moveable.push_back(std::make_unique<Dragon>(createSprite(DRAGON, i, j)));

		}
		for (unsigned int i = 0; i < m_level.getNumOfSquares().y; ++i)
			for (unsigned int j = 0; j < m_level.getNumOfSquares().x; ++j)
				if (m_static[i][j])
					m_static[i][j]->setExistens(true);
		
	

}

int Board::getLevelTime()
{
	return m_levelTime;
}

int Board::currentCharector()
{
	return m_current_char;
}

bool Board::holdingKey()
{
	if (m_moveable[THIEF]->returnKey())
		return true;
	return false;
}

void Board::pushMes(sf::Clock& clock, sf::RenderWindow& window)
{
	std::string str;
	clock.restart();
	str = "you have completed the level";
	m_mes.setText(str);
	m_mes.draw(window);
	window.display();
	while (clock.getElapsedTime().asSeconds() < 2)
	{

    }

}

