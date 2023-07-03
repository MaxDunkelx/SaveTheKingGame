#pragma once
#include <SFML/Graphics.hpp>
#include <vector>

const unsigned int BOARDSIZE_X = 1200;
const unsigned int BOARDSIZE_Y = 750;
const sf::Vector2f BOARDSIZE(1200, 750);
const int PLAYER_SPEED = 350;
auto const TELEPORTMARGIN=13.f;
auto const SECOND = 1;


const enum GameObjects { KING, MAGE, WARRIOR, THIEF, WALL,FIRE,GATE,THRONE,GIFT,TELEPORT,KEY, DWARF, ORC,DRAGON };
const enum MenuObjects { MENU, START,EXIT , HELP };