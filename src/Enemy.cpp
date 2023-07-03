#include"Enemy.h"

Enemy::Enemy(const sf::Sprite& sprite):Movable(sprite)
{
}



void Enemy::draw(sf::RenderWindow& window)
{
    if(this->getExistens())
        window.draw(getSprite());
}
