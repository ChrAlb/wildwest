#pragma once
#include "PlayableCharacter.h"
#include "ResourceHolder.h"
#include "ResourceIdentifiers.h"

class Enemy : public PlayableCharacter
{
public:
	Enemy();
	bool handleInput();
	void update(float dt);

	void set_destination(bool destination);
	
	const int EnemySpeed = 50;

private:
	sf::Vector2f m_destination;
	bool m_hasDestination;

	TextureHolder m_Textures;

};
