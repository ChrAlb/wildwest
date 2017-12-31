#pragma once
#include "PlayableCharacter.h"


class Player : public PlayableCharacter
{
public:
	const int TILE_SIZE = 50; //// Achtung noch doppelt zu  game State
	
	Player::Player();
	
	bool virtual handleInput();
	void update(float dt);
};
