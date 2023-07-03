#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include"GameObject.h"
#include "Macros.h"



class StaticObjects: public GameObject {

public:
	StaticObjects(const sf::Sprite&);
	bool getExistens() const;
	void setExistens(bool booliany);
	virtual void draw(sf::RenderWindow& window) override;

	virtual void handleCollision(Wall& wall)override {};
	virtual void handleCollision(GameObject& obj) override {};
	virtual void handleCollision(King& king) override {};
	virtual void handleCollision(Mage& mage) override {};
	virtual void handleCollision(Warrior& warrior) override {};
	virtual void handleCollision(Thief& thief) override {};
	virtual void handleCollision(Fire& fire) override {};
	virtual void handleCollision(Gate& gate) override {};
	virtual void handleCollision(Gifts& gift)override {};
	virtual void handleCollision(Key& key)override {};
	virtual void handleCollision(Teleport& teleport)override {};
	virtual void handleCollision(Throne& throne) override {};
	virtual void handleCollision(Dragon& dragon) override {};

private:
	bool m_exists;
	

	

};