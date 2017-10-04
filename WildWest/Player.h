#pragma once
#include "PlayableCharacter.h"

class Player : public PlayableCharacter
{
public:
	Player::Player();
	
	void virtual handleInput();
};
