#include "stdafx.h"
#include "Bullet.h"


Bullet::Bullet()
{
	m_otype = t_Bullets;
	
	
	m_Textures.load(Textures::Bullet, "graphics/bullet.png");
	m_Sprite = Sprite(m_Textures.get(Textures::Bullet));

	
}

bool Bullet::handleInput()
{
	return m_JustJumped;
}

void Bullet::update(float dt)
{
	if (m_vel.x > 0)
	{
        m_Position.x  += m_Speed * dt;
	}
	else
	{
		m_Position.x  -= m_Speed * dt;
	}
	
	m_Sprite.setPosition(m_Position);

}

Vector2f Bullet::setm_vel(Vector2f vel)
{
	return m_vel = vel;
}

