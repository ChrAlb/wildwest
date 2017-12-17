
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
	

}

void Enemy::update(float dt)
{
    Enemy::update(dt);
	
	if (m_hasDestination)
	{
		if (abs(m_destination.x - m_Position.x) < 16)
		{
			m_hasDestination = false;
			return;
		}
		if (m_destination.x - m_Position.x > 0)
		{
			m_Position.x += m_Speed * dt;
		}
		else
		{
			m_Position.x -= m_Speed * dt;
		}
		//Hier Collisionstest?
		int random = rand() % 1000 + 1;
		if (random != 1000) { return; }
		int newX = rand() % 65 + 0;
		if (rand() % 2) {newX = -newX; }
		m_destination.x = m_Position.x + newX;
		if (m_destination.x < 0) { m_destination.x = 0; }
		m_hasDestination = true;
		 
	}
	
}