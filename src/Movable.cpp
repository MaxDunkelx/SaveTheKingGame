
#include "Movable.h"



Movable::Movable(const sf::Sprite& sprite) : GameObject(sprite),
m_direction(sf::Vector2f(0, 0)),m_gift(false)
{
	m_gift = false;
}

void Movable::checkGift(bool gift)
{
	m_gift = gift;

}

bool Movable::gotGift()
{
	return m_gift;
}

void Movable::draw(sf::RenderWindow& window)
{
	m_lastLocation = (getSprite().getPosition());
    
	window.draw(getSprite());
}

bool Movable::canMove(float speed, const sf::Vector2f& direction) const
{
	if (getPosition().x + getSize().x + direction.x * speed > (float)BOARDSIZE_X)
		return false;

	if (getPosition().x + direction.x * speed < 0)
		return false;

	if (getPosition().y + getSize().y + direction.y * speed > (float)BOARDSIZE_Y)
		return false;

	if (getPosition().y + direction.y * speed < 0)
		return false;

	return true;
}

const sf::Vector2f& Movable::getDirection() const
{
	return m_direction;
}

const sf::Vector2f& Movable::getLastLocation() const
{
	return m_lastLocation;
}

void Movable::setDirection(const sf::Vector2f& direction)
{
	m_direction = direction;
}

void Movable::setLastLocation(const sf::Vector2f& location)
{
	m_lastLocation = location;
}
