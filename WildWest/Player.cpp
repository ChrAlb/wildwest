#include "stdafx.h"
#include "Player.h"
#include "TextureHolder.h"

#include <iostream>




Player::Player()
{
	
    animations[int(AnimationIndex::WalkingRight)].addRow(0, 0, 80, 100,8);
	animations[int(AnimationIndex::WalkingLeft)].addRow(0, 100, 80, 100,8);
	animations[int(AnimationIndex::Stoping)].addRow(0, 200, 80, 100, 1);

	max_frames[int(AnimationIndex::WalkingRight)] = 8;
	max_frames[int(AnimationIndex::WalkingLeft)] = 8;
	max_frames[int(AnimationIndex::Stoping)] = 1;


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
		dir.x = -1.0f;
		
	}
	else
	{
        m_LeftPressed = false;
	}
		

	if (Keyboard::isKeyPressed(Keyboard::Right))
	{
		m_RightPressed = true;
		dir.x = 1.0f;
	}
	else
	{
		m_RightPressed = false;
	}
	Player::SetDirection(dir);
	return m_JustJumped;

}



void Player::update(float elapsedTime)
{
	int mlevelsize;

	
	if (m_RightPressed)
	{
		m_oldposition = m_Position;
		m_Position.x += m_Speed * elapsedTime;
		
	}

	if (m_LeftPressed)
	{
		m_oldposition = m_Position;
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

	if  (m_isFalling)
	{
		m_Position.y += m_Gravity * elapsedTime;
	} 

  
	if (Player::m_Position.x < 0)
	   {
		Player::m_Position.x = 0;
       }
	

	if ((!m_LeftPressed) && (!m_RightPressed))
	{
		curAnimation = curAnimation = AnimationIndex::Stoping;
	}

	mlevelsize = Player::get_maxlevelsize();

	if (Player::m_Position.x > mlevelsize)
	{
		Player::m_Position.x = mlevelsize;
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
	m_Right.left = r.left + r.width ;
	m_Right.top = r.top + r.height *.35;
	m_Right.width = 1;
	m_Right.height = r.height * .3;

	// Left
	m_Left.left = r.left;
	m_Left.top = r.top + r.height * .35;
	m_Left.width = 1;
	m_Left.height = r.height * .3;

	// Center
	m_Center.left = r.left + (r.width / 2) - 2;
	m_Center.top = r.top + (r.height *.3);
	m_Center.width = 4;
	m_Center.height = r.height - (r.height *.3);

	animations[int(curAnimation)].Update(elapsedTime, max_frames[int(curAnimation)]);
	animations[int(curAnimation)].ApplytoSprite(m_Sprite);
	
	m_Sprite.setPosition(m_Position);	
}
 

void Player::SetDirection(const sf::Vector2f & dir)
{
	m_vel = dir * m_Speed;
	if (dir.x > 0.0f)
	{
		curAnimation = AnimationIndex::WalkingRight;
	}
	else if (dir.x < 0.0f)
	{
		curAnimation = AnimationIndex::WalkingLeft;
	}
}

