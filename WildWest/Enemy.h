#pragma once
#include "PlayableCharacter.h"
#include "ResourceHolder.h"
#include "ResourceIdentifiers.h"
#include "Animation.h"


class Enemy : public PlayableCharacter
{

private:
	enum class AnimationIndex
	{
		WalkingLeft,
		WalkingRight,
		Count
	};

	sf::Vector2f m_destination;
	bool m_hasDestination;

	TextureHolder m_Textures;



public:
	Enemy();
	bool handleInput();
	void update(float dt, Vector2f Plpos);

	void set_destination(bool destination);
	
	const int EnemySpeed = 50;

	Animation animations[int(AnimationIndex::Count)];
	AnimationIndex curAnimation = AnimationIndex::WalkingRight;
	int max_frames[int(AnimationIndex::Count)];



};
