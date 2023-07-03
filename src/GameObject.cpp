#include "..\include\GameObject.h"


GameObject::GameObject(const sf::Sprite& sprite):m_sprite(sprite),m_key(false),m_levelFinish(false)
{
}

bool GameObject::returnKey()
{
	return m_key;
}

void GameObject::findKey(bool booli)
{
	m_key = booli;
}

bool GameObject::LevelFinish()
{
	return m_levelFinish;
}

void GameObject::setLevelFinish()
{
	m_levelFinish = true;
}

const sf::Vector2f& GameObject::getPosition() const
{
	return m_sprite.getPosition();
}

sf::Vector2f GameObject::getSize() const
{
	return sf::Vector2f(m_sprite.getGlobalBounds().width, m_sprite.getGlobalBounds().height);
}

const sf::Sprite& GameObject::getSprite() const
{
	return m_sprite;
}

void GameObject::setPosition(const sf::Vector2f& location)
{
	m_sprite.setPosition(location);
}

void GameObject::setSize(const sf::Vector2f& size)
{
	m_sprite.setScale(size.x / m_sprite.getLocalBounds().width, size.y / m_sprite.getLocalBounds().height);
}

bool GameObject::collidesWith(const GameObject& obj) const
{
	return m_sprite.getGlobalBounds().intersects(obj.m_sprite.getGlobalBounds());
}




