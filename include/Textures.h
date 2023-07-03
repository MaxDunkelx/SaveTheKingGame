#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "Macros.h"

//singleton class
class Textures {
public:
	Textures();
	~Textures();
	///Textures& operator=(const Textures&) = default;
	static Textures& createTex();
	const sf::Texture& getTexture(GameObjects symbol) const;
	const sf::Font& getFont() const;

private:

	///Textures(const Textures&) = default;
	std::vector <sf::Texture> m_Textures;
	sf::Font m_font;
};