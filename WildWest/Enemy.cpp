
#include "stdafx.h"

#include <iostream>
#include "Enemy.h"

Enemy::Enemy() : m_hasDestination(false)
{ 
	m_Textures.load(Textures::Enemy, "graphics/ennemy.png");
	m_Sprite = Sprite(m_Textures.get(Textures::Enemy ));

	m_otype = t_Enemy;
	m_iscollided = false;
	m_is_alive = true;
	m_destination.x = 1;
	m_JustJumped = false;
	m_isFalling = true;

	m_LeftPressed = true;
	m_RightPressed = true;

	
}


bool Enemy::handleInput() 
{
	m_isFalling = true;
	m_vel = m_destination;
	return m_JustJumped;
}

void Enemy::update(float dt)
{    	
	
	m_oldposition = m_Position;

	if (m_isFalling)
	{
		m_Position.y += m_Gravity * dt;
	}
	

	if (m_iscollided) 
	{
		m_iscollided = false;
		//m_destination.x = -m_destination.x;
		//m_Position.x = m_Position.x - 100;
	}

		
	if (m_Position.x < 0) 
	{
		m_Position.x = 0;
		m_destination.x = -m_destination.x;

	}
	

	if (m_Position.x > Enemy::get_maxlevelsize())
	{
		m_Position.x = Enemy::get_maxlevelsize();
		m_destination.x = -m_destination.x;
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

	// Center
	m_Center.left = r.left + (r.width / 2) - 1;
	m_Center.top = r.top + (r.height *.3);
	m_Center.width = 2;
	m_Center.height = r.height - (r.height *.3);

	m_Sprite.setPosition(m_Position);


}

void Enemy::set_destination(bool destination)
{
	if (destination)
	{
		m_destination.x = -m_destination.x;
	}
}

