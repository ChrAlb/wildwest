#include "Enemy.h"
#include "TextureHolder.h"

Enemy::Enemy()
{

	m_Enemy = Sprite(TextureHolder::GetTexture("graphics/Slyppy.png"));

	
}


bool Enemy::handleInput()
{
	


	if (Keyboard::isKeyPressed(Keyboard::Space))
	{
		if (!m_isJumping && !m_isFalling)
		{
			m_isJumping = true;
			m_TimeThisJump = 0;
			m_JustJumped = true;
		}
	}
	else
	{
		m_isJumping = false;
		m_isFalling = true;
	}
	if (Keyboard::isKeyPressed(Keyboard::Left))
	{
		m_LeftPressed = true;
	}
	else
		m_LeftPressed = false;

	if (Keyboard::isKeyPressed(Keyboard::Right))
	{
		m_RightPressed = true;
	}
	else
	{
		m_RightPressed = false;
	}
	return m_JustJumped;

}