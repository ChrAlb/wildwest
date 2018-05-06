#pragma once
#include "PlayableCharacter.h"
#include "Animation.h"
#include "ResourceHolder.h"
#include "ResourceIdentifiers.h"
#include "SoundPlayer.h"


class Player : public PlayableCharacter 

{

private:
	enum class AnimationIndex
	{
		WalkingLeft,
		WalkingRight,
		Stoping,
		Count
	};

	SoundPlayer m_SoundPlayer;
	


public:

	
	void SetDirection(const sf::Vector2f& dir);
	Player::Player();
	
	bool virtual handleInput();
	void update(float dt);

	Animation animations[int(AnimationIndex::Count)];
	AnimationIndex curAnimation = AnimationIndex::Stoping;
	int max_frames[int(AnimationIndex::Count)];
	


	
	

};
