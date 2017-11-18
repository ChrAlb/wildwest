#include "stdafx.h"
#include "Player.h"
#include "TextureHolder.h"
#include <iostream>



Player::Player()
{
	m_Sprite = Sprite(TextureHolder::GetTexture("graphics/Joe.png"));
	m_JumpDuration = .25;
	
}

bool Player::handleInput()
{
	m_JustJumped = false;
	

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