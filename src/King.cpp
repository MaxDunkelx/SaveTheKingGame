#include "..\include\King.h"
#include<iostream>


King::King(const sf::Sprite &sprite):Movable(sprite)
{
}

void King::setKDirection()
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


void King::handleCollision(Wall& wall)
{
	this->setPosition(this->getLastLocation());
}

void King::handleCollision(Fire& fire)
{
	this->setPosition(this->getLastLocation());
}

void King::handleCollision(Gate& gate)
{
	this->setPosition(this->getLastLocation());
}

void King::handleCollision(Throne& throne)
{
	this->setLevelFinish();
}

void King::handleCollision(Gifts& gift)
{
	checkGift(true);
}

void King::handleCollision(Teleport& teleport)
{
	
}

void King::handleCollision(Key& key)
{
}

void King::handleCollision(GameObject& obj)
{
	obj.handleCollision(*this);
}

void King::handleCollision(Mage& mage)
{
	this->setPosition(this->getLastLocation());
}

void King::handleCollision(Warrior& warrior)
{
	this->setPosition(this->getLastLocation());
}

void King::handleCollision(Thief& thief)
{
	this->setPosition(this->getLastLocation());
}

void King::handleCollision(King& king)
{
}

void King::handleCollision(Dwarf& dwarf)
{

	this->setPosition(this->getLastLocation());
}

void King::handleCollision(Orc& orc)
{

	this->setPosition(this->getLastLocation());
	
}

void King::handleCollision(Dragon& dragon)
{
	this->setPosition(this->getLastLocation());
}

unsigned int King::Getindex()
{
	return KING;
}

void King::move(const sf::Time& time)
{
	setKDirection();
	float speed = PLAYER_SPEED * time.asSeconds();
	setLastLocation(getPosition());
	if (canMove(speed, getDirection()))
	{
		auto location = sf::Vector2f(getPosition().x + speed * getDirection().x, getPosition().y + speed * getDirection().y);
		setPosition(location);
	}
}


