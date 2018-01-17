#pragma once
#include "PlayableCharacter.h"

class Enemy : public PlayableCharacter
{
public:
	Enemy();
	bool virtual handleInput();
	void update(float dt);
	
	const int EnemySpeed = 50;

private:
	sf::Vector2f m_destination;
	bool m_hasDestination;

};
