#include "Fire.h"

Fire::Fire(const sf::Sprite& sprite):StaticObjects(sprite)
{

}

void Fire::handleCollision(King& king)
{
	if(getExistens())
	king.handleCollision(*this);
}

void Fire::handleCollision(Mage& mage)
{
	setExistens(false);

}

void Fire::handleCollision(Warrior& warrior)
{
	if (getExistens())
	warrior.handleCollision(*this);
}

void Fire::handleCollision(Thief& thief)
{
	if (getExistens())
	thief.handleCollision(*this);
}

void Fire::handleCollision(Dwarf& dwarf)
{
	if (getExistens())
	dwarf.handleCollision(*this);
}

void Fire::handleCollision(Orc& orc)
{
	if (getExistens())
	 orc.handleCollision(*this);
}
