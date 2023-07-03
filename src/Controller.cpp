#include "Controller.h"
#include<iostream>
#include"Music.h"
#include <SFML/Graphics.hpp>
#include<vector>
#include"Gamestats.h"
Controller::Controller() :m_window(sf::VideoMode(1200, 800), "SAVE_THE_KING", sf::Style::Titlebar | sf::Style::Close)
,m_menu(),m_board(),m_numOfLevel(1), m_textures(Textures::createTex()), m_gamestats(Textures::createTex().getFont()),
m_press(Textures::createTex().getFont())
{

}

void Controller::run()
{
	sf::Sound bGSound(Music::createMusicObj().getSoundbuffer());
	bGSound.setVolume(100);
	bGSound.play();
	bGSound.setLoop(true);
	runMenu();
	waitUntilKeyPress();

	if (!m_board.loadLvl(m_numOfLevel))
	{
		m_board.clearVectors();
		m_window.clear();
		runFinalMenu();
	}

	while (m_window.isOpen())
	{

		m_window.clear();
		m_board.draw(m_window);
		setGameStats();
		m_board.move(m_clock.restart());
		m_board.updateTime();
		m_gamestats.draw(m_window);
		m_window.display();
		

		if (isLvlComplete())
		{
			m_board.clearVectors();
			++m_numOfLevel;
			m_window.clear();
			m_window.display();
			m_board.pushMes(m_clock, m_window);
		



			if (!m_board.loadLvl(m_numOfLevel))//end of game-<<
			{
				bGSound.pause();
				m_board.clearVectors();
				m_window.clear();
				runFinalMenu();

			}
		}



		sf::Event event;
		while (m_window.pollEvent(event))
		{
			switch (event.type)
			{

			case sf::Event::Closed:
			{
				m_window.close();
				break;
			}
			case sf::Event::KeyPressed:
			{
				if (event.key.code == sf::Keyboard::P)
				{
					m_board.nextCharector();
					break;
				}

			}
			}

		}

	}
}


void Controller::runMenu()
{
	while (m_window.isOpen())
	{
		m_window.clear();
		m_menu.draw(m_window);
		m_window.display();
		sf::Event event;
		while (m_window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				m_window.close();

			if (sf::Event::MouseMoved)
			{
				auto location = m_window.mapPixelToCoords(sf::Vector2i(event.mouseMove.x, event.mouseMove.y));
				m_menu.handleMouse(location);
			}

			if (sf::Event::MouseButtonReleased)
			{
				auto location = m_window.mapPixelToCoords(sf::Vector2i(event.mouseButton.x, event.mouseButton.y));
				auto answer = m_menu.whoIsPressed(location);
				if (answer == Start)
					return;
				
				if (answer == Help)
				{
					runHelp();
					runMenu();
				}

				if (answer == Exit)
					m_window.close();
			}
		}
	}


}

void Controller::runFinalMenu()
{
	
	while (m_window.isOpen())
	{

		m_window.clear();
		m_menu.drawFinal(m_window);
		m_window.display();

		sf::Event event;
		while (m_window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				m_window.close();
		}
	}
}

void Controller::runHelp()
{
	while (m_window.isOpen())
	{

		m_window.clear();
		m_menu.drawHelp(m_window);
		m_window.display();

		sf::Event event;
		while (m_window.pollEvent(event))
		{
			setPressHelpMenu(m_window);
			m_window.display();
			while (!isKeyPressed()) {};
			return;
		}

	}
}

bool Controller::isLvlComplete()
{
	if (m_board.isLevelFinished())
		return true;
	return false;
}

void Controller::setGameStats()
{
	if (m_board.getLevelTime() ==-1)//when loading level with '-1' time, you get unlimited time
		m_gamestats.setstring("Time: Unlimited", -1, Time);
	else
		m_gamestats.setstring("Time: ", m_board.getLevelTime(), Time);
	//---------------------------------------------------------------------
	if (m_board.getLevelTime() <= 10 && m_board.getLevelTime() >= 0)
		m_gamestats.changeColor(sf::Color::Red, Time);
	else
		m_gamestats.changeColor(sf::Color::White, Time);
	//---------------------------------------------------------------------

	m_gamestats.setstring("Level: ", m_numOfLevel, Lvl);

	if(m_board.holdingKey())
		m_gamestats.setstring("key: ",1, Key);
	else
		m_gamestats.setstring("key: ", 0, Key);

	if(m_board.currentCharector()==KING)
    m_gamestats.setstring("KING: ", m_board.currentCharector(), Charector);

	if (m_board.currentCharector() == MAGE)
		m_gamestats.setstring("MAGE: ", m_board.currentCharector(), Charector);

	if (m_board.currentCharector() == WARRIOR)
       m_gamestats.setstring("Warrior: ", m_board.currentCharector(), Charector);

	if (m_board.currentCharector() == THIEF)
		m_gamestats.setstring("Thief: ", m_board.currentCharector(), Charector);

}

void Controller::waitUntilKeyPress()
{
	m_window.clear();
	setPress(m_window);
	m_window.display();
	while (!isKeyPressed()) {};
	m_clock.restart();
}

bool Controller::isKeyPressed()
{
	for (int k = -1; k < sf::Keyboard::KeyCount; ++k)
	{
		if (sf::Keyboard::isKeyPressed(static_cast<sf::Keyboard::Key>(k)))
			return true;
	}
	return false;
}

void Controller::setPress(sf::RenderWindow &window)
{
	const sf::Vector2f placement (400.f, 400.f);
	m_press.setPosition(placement);
	std::string str = "press any key to start";
	m_press.setText(str);
	m_press.draw(window);


}

void Controller::setPressHelpMenu(sf::RenderWindow& window)
{
	const sf::Vector2f placement(350.f, 700.f);
	m_press.setPosition(placement);
	std::string str = "press any key to return to Main Menu";
	m_press.setText(str);
	m_press.draw(window);
}


