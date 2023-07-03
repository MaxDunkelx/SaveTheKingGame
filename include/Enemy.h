#pragma once
#include "Movable.h"

class Enemy :public Movable {
public:
	Enemy(const sf::Sprite& sprite);
	virtual void setEDirection() = 0;
	//bool getExistens() override;
	//void setExistense(bool booli) override;
	virtual void draw(sf::RenderWindow& window) override;



private:

	//bool m_exist;
	



};