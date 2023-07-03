#include "Thief.h"

Thief::Thief(const sf::Sprite&sprite):Movable(sprite)
{
}

void Thief::setTDirection()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		setDirection(sf::Vector2f(-1, 0));
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		setDirection(sf::Vector2f(1, 0));
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		setDirection(sf::Vector2f(0, -1));
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		setDirection(sf::Vector2f(0, 1));
	}
	else
		setDirection(sf::Vector2f(0, 0));
}

void Thief::move(const sf::Time& time)
{
	setTDirection();
	float speed = PLAYER_SPEED * time.asSeconds();
	setLastLocation(getPosition());
	if (canMove(speed, getDirection()))
	{
		auto location = sf::Vector2f(getPosition().x + speed * getDirection().x, getPosition().y + speed * getDirection().y);
		setPosition(location);
	}
}

void Thief::handleCollision(Fire& fire)
{
	this->setPosition(this->getLastLocation());
}

void Thief::handleCollision(Wall& wall)
{
	this->setPosition(this->getLastLocation());
}

void Thief::handleCollision(Gate& gate)
{
	this->setPosition(this->getLastLocation());

}

void Thief::handleCollision(Throne& throne)
{
	this->setPosition(this->getLastLocation());
}

void Thief::handleCollision(Gifts& gift)
{
	checkGift(true);
}

void Thief::handleCollision(Teleport& teleport)
{
}

void Thief::handleCollision(Key& key)
{


}

void Thief::handleCollision(GameObject& object)
{
	object.handleCollision(*this);
}

void Thief::handleCollision(Mage& mage)
{
	this->setPosition(this->getLastLocation());
}

void Thief::handleCollision(King& king)
{
	this->setPosition(this->getLastLocation());
}

void Thief::handleCollision(Dwarf& dwarf)
{
	this->setPosition(this->getLastLocation());
}

void Thief::handleCollision(Orc& orc)
{
	
	this->setPosition(this->getLastLocation());
}

void Thief::handleCollision(Dragon& dragon)
{
	this->setPosition(this->getLastLocation());
}

unsigned int Thief::Getindex()
{
	return THIEF;
}

void Thief::handleCollision(Warrior& warrior)
{
	this->setPosition(this->getLastLocation());
}

void Thief::handleCollision(Thief& thief)
{

}
