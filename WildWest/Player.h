#pragma once
#include "PlayableCharacter.h"
#include "Animation.h"



class Player : public PlayableCharacter 

{

private:
	enum class AnimationIndex
	{
		WalkingLeft,
		WalkingRight,
		Count
	};

	


public:

	void SetDirection(const sf::Vector2f& dir);
	Player::Player();
	
	bool virtual handleInput();
	void update(float dt);
	Animation animations[int(AnimationIndex::Count)];
	AnimationIndex curAnimation = AnimationIndex::WalkingRight;
	


	
	

};
