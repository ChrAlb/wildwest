#pragma once
#include "PlayableCharacter.h"

class Player : public PlayableCharacter
{
public:
	float oldpos;
	Player::Player();
	
	bool virtual handleInput();
	void update(float dt);
};
