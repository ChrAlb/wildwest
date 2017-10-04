#pragma once
#include "PlayableCharacter.h"

class Player : public PlayableCharacter
{
public:
	Player::Player();
	
	bool virtual handleInput();
};
