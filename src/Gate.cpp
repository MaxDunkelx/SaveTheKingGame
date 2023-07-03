#include "Gate.h"



Gate::Gate(const sf::Sprite&sprite):StaticObjects(sprite)
{
	
}

void Gate::handleCollision(King& king)
{
	if(this->getExistens())
	king.handleCollision(*this);
}

void Gate::handleCollision(Mage& mage)
{
	if (this->getExistens())
	mage.handleCollision(*this);
}

void Gate::handleCollision(Warrior& warrior)
{
	if (this->getExistens())
	warrior.handleCollision(*this);
}

void Gate::handleCollision(Thief& thief)
{
	if (thief.returnKey() && this->getExistens())
	{
		thief.findKey(false);
		this->setExistens(false);
	}
	else if(this->getExistens() )
	thief.handleCollision(*this);
}

void Gate::handleCollision(Dwarf& dwarf)
{
	if (this->getExistens())
	dwarf.handleCollision(*this);
}

void Gate::handleCollision(Orc& orc)
{
	if (this->getExistens())
	orc.handleCollision(*this);
}
