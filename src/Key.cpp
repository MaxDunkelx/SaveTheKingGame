#include "..\include\Key.h"

Key::Key(const sf::Sprite&sprite):StaticObjects(sprite)
{
}

void Key::handleCollision(King& king)
{
	king.handleCollision(*this);
}

void Key::handleCollision(Mage& mage)
{
	mage.handleCollision(*this);
}

void Key::handleCollision(Warrior& warrior)
{
	
}

void Key::handleCollision(Thief& thief)
{
	if (!thief.returnKey()&& this->getExistens()) {
		this->setExistens(false);
		thief.findKey(true);
	}

	
}

void Key::handleCollision(Dwarf& dwarf)
{
	dwarf.handleCollision(*this);
}

void Key::handleCollision(Orc& orc)
{
	
}

void Key::handleCollision(Dragon& dragon)
{
	if (dragon.getExistens() && !this->getExistens())
		this->setExistens(false);

	else if (!dragon.getExistens() && !this->getExistens())
		this->setExistens(false);

	else if (!dragon.getExistens() && this->getExistens())
		this->setExistens(true);




}
