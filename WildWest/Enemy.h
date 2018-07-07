#pragma once
#include "PlayableCharacter.h"
#include "EnemyAnimation.h"
#include "ResourceHolder.h"
#include "ResourceIdentifiers.h"


class Enemy : public PlayableCharacter
{

private:

	enum class EnemyAnimationIndex
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

	EnemyAnimation animations[int(EnemyAnimationIndex::Count)];
	EnemyAnimationIndex curAnimation = EnemyAnimationIndex::WalkingRight;
	int max_frames[int(EnemyAnimationIndex::Count)];




};
