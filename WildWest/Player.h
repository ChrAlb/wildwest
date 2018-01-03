#pragma once
#include "PlayableCharacter.h"




class Player : public PlayableCharacter 

{
public:

	
	
	Player::Player();
	
	bool virtual handleInput();
	void update(float dt);

	void set_maxlevelsize(int mlevelsize);
	int get_maxlevelsize();

private:
	int m_maxlevelsize;

};
