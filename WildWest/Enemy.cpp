
#include "stdafx.h"
#include "TextureHolder.h"
#include <iostream>
#include "Enemy.h"

Enemy::Enemy() : m_hasDestination(false)
{

	m_Sprite = Sprite(TextureHolder::GetTexture("graphics/Slyppy.png"));

	
}


bool Enemy::handleInput() 
{
	m_JustJumped = false;
	return m_JustJumped;

}

void Enemy::update(float dt)
{
    //Enemy::update(dt);
/*	
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
	 
	}  */
	m_Position.x += (m_Speed/25) * dt;
	if (m_isFalling)
	{
		m_Position.y += m_Gravity * dt;
	}


	FloatRect r = getPosition();

	// Feet
	m_Feet.left = r.left + 3;
	m_Feet.top = r.top + r.height - 1;
	m_Feet.width = r.width - 6;
	m_Feet.height = 1;

	// Head
	m_Head.left = r.left;
	m_Head.top = r.top + (r.height *.3);
	m_Head.width = r.width;
	m_Head.height = 1;

	// Right
	m_Right.left = r.left + r.width - 2 - 25;
	m_Right.top = r.top + r.height *.35;
	m_Right.width = 1;
	m_Right.height = r.height * .3;

	// Left
	m_Left.left = r.left + 25;
	m_Left.top = r.top + r.height * .35;
	m_Left.width = 1;
	m_Left.height = r.height * .3;

	m_Sprite.setPosition(m_Position);


}