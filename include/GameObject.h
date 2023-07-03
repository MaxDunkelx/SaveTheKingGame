#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class King;
class Mage;
class Warrior;
class Thief;

class Wall;
class Gifts;
class Throne;
class Gate;
class Fire;
class Key;
class Teleport;
class Dwarf;
class Orc;
class Dragon;


//abstract class - basic class for all objects in the game
class GameObject
{
public:

	GameObject(const sf::Sprite& sprite);
	bool returnKey();
	void findKey(bool booli);
	bool LevelFinish();
	void setLevelFinish();
	virtual void draw(sf::RenderWindow& window) = 0;
	const sf::Vector2f& getPosition() const;
	sf::Vector2f getSize() const;
	const sf::Sprite& getSprite() const;
	virtual void setPosition(const sf::Vector2f& location);
	void setSize(const sf::Vector2f& size);
    bool collidesWith(const GameObject& obj) const;
	
	virtual void handleCollision(GameObject& obj) = 0;
	virtual void handleCollision(King & king) = 0;
	virtual void handleCollision(Mage& mage) = 0;
	virtual void handleCollision(Warrior& warrior) = 0;
	virtual void handleCollision(Thief& thief) = 0;
	virtual void handleCollision(Wall& wall) = 0;
	virtual void handleCollision(Fire& fire) = 0;
	virtual void handleCollision(Gate& gate) = 0;
	virtual void handleCollision(Throne& throne) = 0;
	virtual void handleCollision(Gifts& gift) = 0;
	virtual void handleCollision(Teleport& teleport) = 0;
	virtual void handleCollision(Key& key) = 0;
	virtual void handleCollision(Dwarf& dwarf) = 0;
	virtual void handleCollision(Orc& orc) = 0;
	virtual void handleCollision(Dragon& dragon) = 0;
	
private:
	sf::Sprite m_sprite;
	bool m_key;
	bool m_levelFinish;

};