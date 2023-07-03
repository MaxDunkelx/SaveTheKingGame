#pragma once
#include<vector>
#include <SFML/Graphics.hpp>
#include"Macros.h"
#include"Movable.h"
class Mage :public Movable {

public:
	Mage(const sf::Sprite&);
	virtual void move(const sf::Time& time) override;
	void setMDirection();

	virtual void handleCollision(Wall& wall)override;
	virtual void handleCollision(Fire& fire)override;
	virtual void handleCollision(Gate& gate)override;
	virtual void handleCollision(Throne& throne)override;
	virtual void handleCollision(Gifts& gift)override;
	virtual void handleCollision(GameObject& object)override;
	virtual void handleCollision(Teleport& teleport)override;
	virtual void handleCollision(Key& key)override;

	virtual void handleCollision(Mage& mage) override;
	virtual void handleCollision(King& king) override;
	virtual void handleCollision(Warrior& warrior) override;
	virtual void handleCollision(Thief& thief) override;
	virtual void handleCollision(Dwarf& dwarf) override;
	virtual void handleCollision(Orc& orc) override;
	virtual void handleCollision(Dragon& dragon) override;

	virtual unsigned int Getindex() override;
	virtual bool getExistens() override { return true; };
	virtual void setExistense(bool) override {};


private:


};

