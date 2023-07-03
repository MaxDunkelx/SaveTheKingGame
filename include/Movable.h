#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "GameObject.h"
#include "Macros.h"



class Movable : public GameObject {

public:

	Movable(const sf::Sprite& sprite);
	virtual bool getExistens()=0 ;
	virtual void setExistense(bool )=0;
	void checkGift(bool gift);
	bool gotGift();
	virtual unsigned int Getindex()=0;
	virtual void move(const sf::Time& time) = 0;
	virtual void draw(sf::RenderWindow& window) override;
	bool canMove(float speed, const sf::Vector2f& direction) const;
	const sf::Vector2f& getDirection() const;
	const sf::Vector2f& getLastLocation() const;
	void setDirection(const sf::Vector2f& direction);
	void setLastLocation(const sf::Vector2f& location);

	

private:
	sf::Vector2f m_direction;
	sf::Vector2f m_lastLocation;
	bool m_gift;

};