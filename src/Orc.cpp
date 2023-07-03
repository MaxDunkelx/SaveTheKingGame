#include "..\include\Orc.h"

Orc::Orc(const sf::Sprite& sprite):Enemy(sprite),m_exist(true)
{
	m_clock.restart();
}

void Orc::move(const sf::Time& time)
{
	
	setEDirection();
	float speed = 30 * time.asSeconds();
	setLastLocation(getPosition());

	if (canMove(speed, getDirection()) && this->getExistens())
	{
		auto location = sf::Vector2f(getPosition().x + speed * getDirection().x,
			getPosition().y + speed * getDirection().y);

		if (location.x >= (float)BOARDSIZE_X)
			setDirection(sf::Vector2f(getDirection().x * -1, 0));//Reverse the direction

		if (location.y >= (float)BOARDSIZE_Y)
			setDirection(sf::Vector2f(0, getDirection().y * -1));//Reverse the direction

		if (location.x <= 0)
			setDirection(sf::Vector2f(getDirection().x * -1, 0));//Reverse the direction

		if (location.y <= 0)
			setDirection(sf::Vector2f(0, getDirection().y * -1));//Reverse the direction


		setPosition(location);
	}
	
}

void Orc::handleCollision(Wall& wall)
{
	this->setPosition(this->getLastLocation());
}

void Orc::handleCollision(Fire& fire)
{
	this->setPosition(this->getLastLocation());
}

void Orc::handleCollision(Gate& gate)
{
	this->setPosition(this->getLastLocation());
}

void Orc::handleCollision(Throne& throne)
{
	this->setPosition(this->getLastLocation());
}

void Orc::handleCollision(Gifts& gift)
{
}

void Orc::handleCollision(Teleport& teleport)
{
}

void Orc::handleCollision(Key& key)
{
}

void Orc::handleCollision(GameObject& obj)
{
	obj.handleCollision(*this);
}

void Orc::handleCollision(Mage& mage)
{
	if (getExistens())
	{
		mage.handleCollision(*this);
		this->setPosition(this->getLastLocation());
	}
}

void Orc::handleCollision(Warrior& warrior)
{   
	setExistense(false);

}

void Orc::handleCollision(Thief& thief)
{
	
	if (getExistens())
	{
		this->setPosition(this->getLastLocation());
		thief.handleCollision(*this);
	
	}
}

void Orc::handleCollision(King& king)
{
	if (getExistens())
	{
		this->setPosition(this->getLastLocation());
		king.handleCollision(*this);
	}
}

void Orc::handleCollision(Dwarf& dwarf)
{
	if (getExistens()) {
		this->setPosition(this->getLastLocation());
		
	}
	
}

void Orc::handleCollision(Orc& orc)
{
	if (getExistens()) {
		this->setPosition(this->getLastLocation());
	
	}
}

void Orc::handleCollision(Dragon& dragon)
{
	this->setPosition(this->getLastLocation());
}

unsigned int Orc::Getindex()
{
	return ORC;
}

bool Orc::getExistens()
{
	return m_exist;
}

void Orc::setExistense(bool cur)
{
	m_exist = cur;
}

void Orc::setEDirection()
{
	int side;
	if (m_clock.getElapsedTime().asSeconds() > 1)
	{
		m_clock.restart();
		side = rand() % 5;
	}
	else
		side = 5;
	switch (side)
	{
	case 0://right

		setDirection(sf::Vector2f(1, 0));
		break;

	case 1://left
		setDirection(sf::Vector2f(-1, 0));
		break;

	case 3://up
		setDirection(sf::Vector2f(0, -1));
		break;

	case 4://down
		setDirection(sf::Vector2f(0, 1));
		break;

	case5:
		setDirection(sf::Vector2f(0, 0));
		break;
	}
}
