#include "Mage.h"
#include<iostream>


Mage::Mage(const sf::Sprite&sprite):Movable(sprite)
{
	
}

void Mage::move(const sf::Time& time)
{
	setMDirection();
	float speed = PLAYER_SPEED * time.asSeconds();
	setLastLocation(getPosition());
	if (canMove(speed, getDirection()))
	{
		auto location = sf::Vector2f(getPosition().x + speed * getDirection().x, getPosition().y + speed * getDirection().y);
		setPosition(location);
	}
}

void Mage::setMDirection()
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

void Mage::handleCollision(Wall& wall)
{
	this->setPosition(this->getLastLocation());
}

void Mage::handleCollision(Fire& fire)
{
	
}

void Mage::handleCollision(Gate& gate)
{
	this->setPosition(this->getLastLocation());
}

void Mage::handleCollision(Throne& throne)
{
	this->setPosition(this->getLastLocation());
}

void Mage::handleCollision(Gifts& gift)
{
	checkGift(true);
}

void Mage::handleCollision(GameObject& obj)
{
	obj.handleCollision(*this);
}

void Mage::handleCollision(Teleport& teleport)
{
}

void Mage::handleCollision(Key& key)
{
}

void Mage::handleCollision(Mage& mage)
{
}

void Mage::handleCollision(King& king)
{
	this->setPosition(this->getLastLocation());
}

void Mage::handleCollision(Warrior& warrior)
{
	this->setPosition(this->getLastLocation());
}

void Mage::handleCollision(Thief& thief)
{
	this->setPosition(this->getLastLocation());
}

void Mage::handleCollision(Dwarf& dwarf)
{
	this->setPosition(this->getLastLocation());
}

void Mage::handleCollision(Orc& orc)
{
	
	this->setPosition(this->getLastLocation());
}

void Mage::handleCollision(Dragon& dragon)
{
	this->setPosition(this->getLastLocation());
}

unsigned int Mage::Getindex()
{
	return MAGE;
}


