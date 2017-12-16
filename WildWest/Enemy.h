#pragma once
#include "PlayableCharacter.h"

class Enemy : public PlayableCharacter
{
public:
	Enemy();
	bool virtual handleInput();

private:
	sf::Vector2f m_destination;
	bool m_hasDestination;

};
