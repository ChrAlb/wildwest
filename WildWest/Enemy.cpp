
#include "stdafx.h"
#include "TextureHolder.h"
#include <iostream>
#include "Enemy.h"

Enemy::Enemy() : m_hasDestination(false)
{

	m_Enemy = Sprite(TextureHolder::GetTexture("graphics/Slyppy.png"));

	
}


bool Enemy::handleInput(float dt) 
{
	PlayableCharacter::update(dt);
	
	if (m_hasDestination)
	{
		//if (abs(m_destination.x - m_Po))  Hier weiter bauen.....
	}
	return true;

}