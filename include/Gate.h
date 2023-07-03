#pragma once
#include <SFML/Graphics.hpp>
#include"Macros.h"
#include "StaticObjects.h"
#include "King.h"
#include"Mage.h"
#include"Warrior.h"
#include"Thief.h"
#include "Dwarf.h"
#include"Orc.h"
class Gate :public StaticObjects {
	using StaticObjects::StaticObjects;

public:
	Gate(const sf::Sprite&);
	virtual void handleCollision(King& king) override;
	virtual void handleCollision(Mage& mage) override;
	virtual void handleCollision(Warrior& warrior) override;
	virtual void handleCollision(Thief& thief) override;
	virtual void handleCollision(Dwarf& dwarf) override;
	virtual void handleCollision(Orc& orc) override;
private:



};