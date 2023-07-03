#include"Macros.h"
#include "Textures.h"
#include<iostream>
Textures::Textures()
{


	    m_font.loadFromFile("font.ttf");
	
		auto tex = sf::Texture();

		tex.loadFromFile("king.png");
		m_Textures.push_back(tex);

		tex.loadFromFile("mage.png");
		m_Textures.push_back(tex);

		tex.loadFromFile("warrior.png");
		m_Textures.push_back(tex);

		tex.loadFromFile("thief.png");
		m_Textures.push_back(tex);

		tex.loadFromFile("wall.png");
		m_Textures.push_back(tex);

		tex.loadFromFile("fire.png");
		m_Textures.push_back(tex);

		tex.loadFromFile("gate.png");
		m_Textures.push_back(tex);

		tex.loadFromFile("throne.png");
		m_Textures.push_back(tex);

		tex.loadFromFile("gift.png");
		m_Textures.push_back(tex);

		tex.loadFromFile("teleport.png");
		m_Textures.push_back(tex);

		tex.loadFromFile("key.png");
		m_Textures.push_back(tex);

		tex.loadFromFile("dwarf.png");
		m_Textures.push_back(tex);

		tex.loadFromFile("orc.png");
		m_Textures.push_back(tex);

		tex.loadFromFile("dragon.png");
		m_Textures.push_back(tex);
		
}

Textures::~Textures()
{
}

Textures& Textures::createTex()
{
	static Textures tex;
	return tex;
}

const sf::Texture& Textures::getTexture(GameObjects symbol) const
{
	return m_Textures[symbol];
}



const sf::Font& Textures::getFont() const
{
	return m_font;
}

