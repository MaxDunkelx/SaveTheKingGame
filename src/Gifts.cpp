#include "Gifts.h"

Gifts::Gifts(const sf::Sprite&sprite):StaticObjects(sprite)
{
}

void Gifts::handleCollision(King& king)
{
	if (getExistens()) {
		this->setExistens(false);
		king.handleCollision(*this);
	}
	
}

void Gifts::handleCollision(Mage& mage)
{
	if (getExistens()) {
		this->setExistens(false);
		mage.handleCollision(*this);
	}

}

void Gifts::handleCollision(Warrior& warrior)
{
	if (getExistens()) {
		this->setExistens(false);
		warrior.handleCollision(*this);
	}


}

void Gifts::handleCollision(Thief& thief)
{
	if (getExistens()) {
		this->setExistens(false);
		thief.handleCollision(*this);
	}

}

void Gifts::handleCollision(Dwarf& dwarf)
{
}

void Gifts::handleCollision(Orc& orc)
{
}
