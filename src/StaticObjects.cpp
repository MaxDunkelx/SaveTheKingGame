#include"StaticObjects.h"



StaticObjects::StaticObjects(const sf::Sprite&sprite):GameObject(sprite), m_exists(true)
{
}

bool StaticObjects::getExistens() const
{
	return m_exists;
}

void StaticObjects::setExistens(bool display)
{
	m_exists = display;
}



void StaticObjects::draw(sf::RenderWindow& window)
{
	if (m_exists)
		window.draw(getSprite());
}



