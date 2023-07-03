#pragma once
#include<vector>
#include <SFML/Graphics.hpp>
#include"Movable.h"


class Thief :public Movable {

public:
	Thief(const sf::Sprite&);
	void setTDirection();

	virtual void move(const sf::Time& time) override;

	virtual void handleCollision(Fire& fire)override;
	virtual void handleCollision(Wall& wall)override;
	virtual void handleCollision(Gate& gate)override;
	virtual void handleCollision(Throne& throne)override;
	virtual void handleCollision(Gifts& gift)override;
	virtual void handleCollision(Teleport& teleport)override;
	virtual void handleCollision(Key& key)override;
	virtual void handleCollision(GameObject& obj)override;
	virtual void handleCollision(Mage& mage) override;
	virtual void handleCollision(Warrior& warrior) override;
	virtual void handleCollision(Thief& thief) override;
	virtual void handleCollision(King& king) override;
	virtual void handleCollision(Dwarf& dwarf) override;
	virtual void handleCollision(Orc& orc) override;
	virtual void handleCollision(Dragon& dragon) override;

	virtual unsigned int Getindex() override;
	virtual bool getExistens() override { return true; };
	virtual void setExistense(bool) override { };

private:


};