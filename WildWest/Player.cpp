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

void Player::update(float elapsedTime)
{
	//m_isFalling = false;  // Hier stimmt was nicht: is Falling wird vom Konstruktur auf true gesetzt?

	if (m_RightPressed)
	{
		m_Position.x += m_Speed * elapsedTime;
	}

	if (m_LeftPressed)
	{
		m_Position.x -= m_Speed * elapsedTime;
	}

	if (m_isJumping)
	{
		m_TimeThisJump += elapsedTime;

		if (m_TimeThisJump < m_JumpDuration)
		{
			m_Position.y -= m_Gravity * 2 * elapsedTime;
		}
		else
		{
			m_isJumping = false;
			m_isFalling = true;
		}
	}

	if (m_isFalling)
	{
		m_Position.y += m_Gravity * elapsedTime;
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