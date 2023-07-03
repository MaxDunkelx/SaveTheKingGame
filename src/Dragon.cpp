#include"Dragon.h"




Dragon::Dragon(const sf::Sprite& sprite) :Enemy(sprite), m_exist(true)
{
}


void Dragon::move(const sf::Time& time)
{

}

void Dragon::handleCollision(Wall& wall)
{
}

void Dragon::handleCollision(Fire& fire)
{

}

void Dragon::handleCollision(Gate& gate)
{

}

void Dragon::handleCollision(Throne& throne)
{
}

void Dragon::handleCollision(Gifts& gift)
{
}

void Dragon::handleCollision(Teleport& teleport)
{
}



void Dragon::setEDirection()
{
	
}

void Dragon::handleCollision(Key& key)
{

}

void Dragon::handleCollision(GameObject& obj)
{
	obj.handleCollision(*this);
}

void Dragon::handleCollision(Mage& mage)
{
	if (getExistens()) {
		mage.handleCollision(*this);
	}
}

void Dragon::handleCollision(Warrior& warrior)
{
	if (getExistens())
	this->setExistense(false);
}


void Dragon::handleCollision(Thief& thief)
{
	if (getExistens()) 
		thief.handleCollision(*this);
	
}

void Dragon::handleCollision(King& king)
{
	if (getExistens()) 
		king.handleCollision(*this);
	
}

void Dragon::handleCollision(Dwarf& dwarf)
{

	if (getExistens()) 
		dwarf.handleCollision(*this);
	
}

void Dragon::handleCollision(Orc& orc)
{
	if (getExistens())
	orc.handleCollision(*this);

}

void Dragon::handleCollision(Dragon& dragon)
{
}

unsigned int Dragon::Getindex()
{
	return DRAGON;
}

bool Dragon::getExistens()
{
	return m_exist;
}

void Dragon::setExistense(bool cur)
{
	m_exist = cur;
}






