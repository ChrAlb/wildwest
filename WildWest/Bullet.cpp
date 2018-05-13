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
	m_Position.x += 25 *dt ;
	m_Sprite.setPosition(m_Position);

}

