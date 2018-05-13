#include "stdafx.h"
#include "Bullet.h"


Bullet::Bullet()
{
	m_otype = t_Bullets;
	
	
	m_Textures.load(Textures::Bullet, "graphics/bullet.png");
	//m_Sprite(bullet);

}

bool Bullet::handleInput()
{
	return false;
}

void Bullet::update(float dt)
{
	m_Position.x += m_Speed * dt;
	m_Sprite.setPosition(m_Position);
}

