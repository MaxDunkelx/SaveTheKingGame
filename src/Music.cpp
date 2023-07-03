#include"Music.h"

Music::Music()
{
	m_sound_buffer.loadFromFile("GameMusic.ogg");
}

Music::~Music()
{
}

Music& Music::createMusicObj()
{
	static Music music;
	return music;
}

const sf::SoundBuffer& Music::getSoundbuffer() const
{
	return m_sound_buffer;
}
