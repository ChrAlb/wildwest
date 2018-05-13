
#include "stdafx.h"

#include <iostream>
#include "Enemy.h"

Enemy::Enemy() : m_hasDestination(false)
{
	m_Textures.load(Textures::Enemy, "graphics/Slyppy.png");
	m_Sprite = Sprite(m_Textures.get(Textures::Enemy ));

	m_otype = t_Enemy;
	m_iscollided = false;
}


bool Enemy::handleInput() 
{
	m_JustJumped = false;
	m_isFalling = true;
	return m_JustJumped;
}

void Enemy::update(float dt)
{    	
	
	if (m_isFalling)
	{
		m_Position.y += m_Gravity * dt;
	}
	
	m_destination.x = 1;

	if (!m_hasDestination)
	{
		if (int random = rand() % 2);
		{
			m_destination.x = -m_destination.x;
			m_hasDestination = true;
		}		
	}

	if (m_iscollided)
	{
		m_hasDestination = false;
	}

	
	if (Enemy::m_Position.x < 0)
	{
		Enemy::m_Position.x = 0;
		m_hasDestination = false;
	}
	

	if (Enemy::m_Position.x > Enemy::get_maxlevelsize())
	{
		Enemy::m_Position.x = Enemy::get_maxlevelsize();
		m_hasDestination = false;
  	}
    
	m_Position.x +=  EnemySpeed * m_destination.x * dt;

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
	m_Right.left = r.left + r.width ;
	m_Right.top = r.top + r.height *.35;
	m_Right.width = 1;
	m_Right.height = r.height * .3;

	// Left
	m_Left.left = r.left ;
	m_Left.top = r.top + r.height * .35;
	m_Left.width = 1;
	m_Left.height = r.height * .3;

	m_Sprite.setPosition(m_Position);


}


