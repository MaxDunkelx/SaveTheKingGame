
#include "..\include\Warrior.h"


Warrior::Warrior(const sf::Sprite& sprite):Movable(sprite)
{
}

void Warrior::setWDirection()
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

void Warrior::move(const sf::Time& time)
{
	setWDirection();
	float speed = PLAYER_SPEED * time.asSeconds();
	setLastLocation(getPosition());

	if (canMove(speed, getDirection()))
	{
		auto location = sf::Vector2f(getPosition().x + speed * getDirection().x, getPosition().y + speed * getDirection().y);
		setPosition(location);
	}
}

void Warrior::handleCollision(Wall& wall)
{
	this->setPosition(this->getLastLocation());
}

void Warrior::handleCollision(Fire& fire)
{
	this->setPosition(this->getLastLocation());
}

void Warrior::handleCollision(Gate& gate)
{
	this->setPosition(this->getLastLocation());
}

void Warrior::handleCollision(Throne& throne)
{
	this->setPosition(this->getLastLocation());
}

void Warrior::handleCollision(Gifts& gift)
{
	checkGift(true);
}

void Warrior::handleCollision(Teleport& teleport)
{
}

void Warrior::handleCollision(Key& key)
{
}

void Warrior::handleCollision(Dwarf& dwarf)
{
	this->setPosition(this->getLastLocation());
}

void Warrior::handleCollision(Orc& orc)
{
	
	
}

void Warrior::handleCollision(Dragon& dragon)
{
	this->setPosition(this->getLastLocation());
}

void Warrior::handleCollision(GameObject& object)
{
	object.handleCollision(*this);
}

void Warrior::handleCollision(Mage& mage)
{
	this->setPosition(this->getLastLocation());
}

void Warrior::handleCollision(King& king)
{
	this->setPosition(this->getLastLocation());
}

void Warrior::handleCollision(Warrior& warrior)
{
	
}

void Warrior::handleCollision(Thief& thief)
{
	this->setPosition(this->getLastLocation());
}

unsigned int Warrior::Getindex()
{
	return WARRIOR;
}

