#pragma once
#include <SFML/Audio.hpp>
class Music {

public:

	Music();
	~Music();
	static Music& createMusicObj();
	const sf::SoundBuffer& getSoundbuffer() const;

private:

	sf::SoundBuffer m_sound_buffer;



};