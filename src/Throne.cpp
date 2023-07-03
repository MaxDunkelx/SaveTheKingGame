#include "Throne.h"



Throne::Throne(const sf::Sprite&sprite):StaticObjects(sprite)
{
}

void Throne::handleCollision(King& king)
{
	king.handleCollision(*this);
}

void Throne::handleCollision(Mage& mage)
{
	mage.handleCollision(*this);
}

void Throne::handleCollision(Warrior& warrior)
{
	warrior.handleCollision(*this);
}

void Throne::handleCollision(Thief& thief)
{
	thief.handleCollision(*this);
}

void Throne::handleCollision(Dwarf& dwarf)
{
	dwarf.handleCollision(*this);
}

void Throne::handleCollision(Orc& orc)
{
	orc.handleCollision(*this);
}
