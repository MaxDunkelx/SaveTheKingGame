
#include "Menu.h"
#include "..\include\Menu.h"



Menu::Menu() :m_background(), m_start(), m_exit(), m_help()
	{
	static sf::Texture background;
	static sf::Texture start;
	static sf::Texture exit;
	static sf::Texture gameover;
	static sf::Texture help;
	static sf::Texture helpmenu;

	background.loadFromFile("menu.png");
	start.loadFromFile("start.png");
	help.loadFromFile("help.png");
	exit.loadFromFile("exit.png");
	gameover.loadFromFile("gameover.png");
	helpmenu.loadFromFile("helpmenu.png");

	m_background.setTexture(background);
	m_background.setScale((BACKGROUNDSIZE.x / m_background.getLocalBounds().width), (BACKGROUNDSIZE.y / m_background.getLocalBounds().height));
	m_background.setPosition(sf::Vector2f(0, 0));


	m_start.setTexture(start);
	m_start.setScale((BUTTON_SIZE.x / m_start.getLocalBounds().width), (BUTTON_SIZE.y / m_start.getLocalBounds().height));
	m_start.setPosition(BACKGROUNDSIZE.x / 2 - (BUTTON_SIZE.x / 2), (BACKGROUNDSIZE.y / 2));

	m_help.setTexture(help);
	m_help.setScale((BUTTON_SIZE.x / m_help.getLocalBounds().width), (BUTTON_SIZE.y / m_help.getLocalBounds().height));
	m_help.setPosition(BACKGROUNDSIZE.x / 2 - (BUTTON_SIZE.x / 2), (BACKGROUNDSIZE.y / 2 + 10.0f) + BUTTON_SIZE.y);

	m_exit.setTexture(exit);
	m_exit.setScale((BUTTON_SIZE.x / m_exit.getLocalBounds().width), (BUTTON_SIZE.y / m_exit.getLocalBounds().height));
	m_exit.setPosition(BACKGROUNDSIZE.x / 2 - (BUTTON_SIZE.x / 2), (BACKGROUNDSIZE.y / 2 + 130.0f) + BUTTON_SIZE.y);

	m_helpMenu.setTexture(helpmenu);
	m_helpMenu.setScale((BACKGROUNDSIZE.x / m_helpMenu.getLocalBounds().width), (BACKGROUNDSIZE.y / m_helpMenu.getLocalBounds().height));
	m_helpMenu.setPosition(sf::Vector2f(0, 0));

	m_GameOver.setTexture(gameover);
	m_GameOver.setScale((BACKGROUNDSIZE.x / m_GameOver.getLocalBounds().width), (BACKGROUNDSIZE.y / m_GameOver.getLocalBounds().height));
	m_GameOver.setPosition(sf::Vector2f(0, 0));
}

void Menu::handleMouse(const sf::Vector2f& location)
{
	{
		if (m_start.getGlobalBounds().contains(location))
			m_start.setColor(sf::Color::Green);

		else if (m_help.getGlobalBounds().contains(location))
			m_help.setColor(sf::Color::Green);

		else if (m_exit.getGlobalBounds().contains(location))
			m_exit.setColor(sf::Color::Green);
		else
		{
			m_start.setColor(sf::Color::White);
			m_help.setColor(sf::Color::White);
			m_exit.setColor(sf::Color::White);
		}

	}
}

void Menu::draw(sf::RenderWindow& window) const
{
	window.draw(m_background);
	window.draw(m_start);
	window.draw(m_help);
	window.draw(m_exit);
}

void Menu::drawFinal(sf::RenderWindow& window) const
{
	window.draw(m_GameOver);

}

void Menu::drawHelp(sf::RenderWindow& window) const
{
	window.draw(m_helpMenu);
}

Button Menu::whoIsPressed(const sf::Vector2f& location)
{
	if (m_start.getGlobalBounds().contains(location))
		return Start;
	else if (m_help.getGlobalBounds().contains(location))
		return Help;

	else if (m_exit.getGlobalBounds().contains(location))
		return Exit;
	else
		return Nothing;
}


