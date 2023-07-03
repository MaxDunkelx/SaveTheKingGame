#include "..\include\Dwarf.h"
#include "..\include\Dwarf.h"



Dwarf::Dwarf(const sf::Sprite& sprite, King* king):Enemy(sprite),m_king(king),m_exist(true)
{
}

void Dwarf::move(const sf::Time& time)
{

setEDirection();
float speed = 30 * time.asSeconds();

setLastLocation(getPosition());

auto location = sf::Vector2f(getPosition().x + speed * getDirection().x, getPosition().y + speed * getDirection().y);
if (canMove(speed, getDirection()) &&this->getExistens())
{
if (location.x >=(float)BOARDSIZE_X)
setDirection(sf::Vector2f(getDirection().x * -1, 0));//Reverse the direction

 if (location.y >=(float)BOARDSIZE_Y)
setDirection(sf::Vector2f(0, getDirection().y * -1));//Reverse the direction

 if (location.x <= 0)
	 setDirection(sf::Vector2f(getDirection().x * -1, 0));//Reverse the direction

 if (location.x <=0)
	 setDirection(sf::Vector2f(0, getDirection().y * -1));//Reverse the direction


	auto location = sf::Vector2f(getPosition().x + speed * getDirection().x,getPosition().y + speed * getDirection().y);
	setPosition(location);
}

else if (location.x> (float)BOARDSIZE_X)
setDirection(sf::Vector2f(getDirection().x * -1, 0));//Reverse the direction

else if (location.x > (float)BOARDSIZE_Y)
setDirection(sf::Vector2f(0,getDirection().y*-1));//Reverse the direction

}

void Dwarf::handleCollision(Wall& wall)
{
	this->setPosition(this->getLastLocation());
}

void Dwarf::handleCollision(Fire& fire)
{
	this->setPosition(this->getLastLocation());
}

void Dwarf::handleCollision(Gate& gate)
{
	this->setPosition(this->getLastLocation());
}

void Dwarf::handleCollision(Throne& throne)
{
	this->setPosition(this->getLastLocation());
}

void Dwarf::handleCollision(Gifts& gift)
{
}

void Dwarf::handleCollision(Teleport& teleport)
{
}

void Dwarf::setEDirection()
{
	auto path1 =abs(getPosition().x- m_king->getPosition().x);
	auto path2 =abs(getPosition().y - m_king->getPosition().y);
	
if (getPosition().x > m_king->getPosition().x &&path2<path1)
		setDirection(sf::Vector2f(-1, 0));//left

else if (getPosition().x < m_king->getPosition().x && path2 < path1)
	setDirection(sf::Vector2f(1, 0));//right

else if (getPosition().y > m_king->getPosition().y && path2 > path1)
setDirection(sf::Vector2f(0, -1));//up

else  if (getPosition().y < m_king->getPosition().y && path2 > path1)
		setDirection(sf::Vector2f(0, 1));//down
}

void Dwarf::handleCollision(Key& key)
{
}

void Dwarf::handleCollision(GameObject& obj)
{
	obj.handleCollision(*this);
}

void Dwarf::handleCollision(Mage& mage)
{
	if (getExistens()) {
		this->setPosition(this->getLastLocation());
		mage.handleCollision(*this);
	}
}

void Dwarf::handleCollision(Warrior& warrior)
{
	if (getExistens())
	{
		this->setPosition(this->getLastLocation());
		warrior.handleCollision(*this);
	}
}
	

void Dwarf::handleCollision(Thief& thief)
{
	if (getExistens()) {
		this->setPosition(this->getLastLocation());
		thief.handleCollision(*this);
	}
}

void Dwarf::handleCollision(King& king)
{
	if (getExistens()) {
		this->setPosition(this->getLastLocation());
		king.handleCollision(*this);
	}
}

void Dwarf::handleCollision(Dwarf& dwarf)
{

	if (getExistens()) {
		this->setPosition(this->getLastLocation());
		dwarf.handleCollision(*this);
	}
}

void Dwarf::handleCollision(Orc& orc)
{
	if (getExistens()) 
	{
		this->setPosition(this->getLastLocation());
		orc.handleCollision(*this);
	}
	
}

void Dwarf::handleCollision(Dragon& dragon)
{
	this->setPosition(this->getLastLocation());
}

unsigned int Dwarf::Getindex()
{
	return DWARF;
}

bool Dwarf::getExistens()
{
	return m_exist;
}

void Dwarf::setExistense(bool cur)
{
	m_exist = cur;
}






