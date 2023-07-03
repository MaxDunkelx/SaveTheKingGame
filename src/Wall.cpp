
#include "Wall.h"

Wall::Wall(const sf::Sprite&sprite):StaticObjects(sprite)
{
}

void Wall::handleCollision(King& king)
{
	king.handleCollision(*this);
}

void Wall::handleCollision(Mage& mage)
{
	mage.handleCollision(*this);
}

void Wall::handleCollision(Warrior& warrior)
{
	warrior.handleCollision(*this);
}

void Wall::handleCollision(Thief& thief)
{
	thief.handleCollision(*this);
}

void Wall::handleCollision(Dwarf& dwarf)
{
	dwarf.handleCollision(*this);
}

void Wall::handleCollision(Orc& orc)
{
	orc.handleCollision(*this);
}
