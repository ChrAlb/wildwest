#include "stdafx.h"
#include "PlayableCharacter.h"
#include <iostream>

PlayableCharacter::PlayableCharacter() : m_id(0)
{
	m_leftslope_end = false;
	m_rightslope_end = false;
	m_on_slope = false;
	tile_pos = { 0,0 };
}

void PlayableCharacter::spawn(Vector2f startPosition, float gravity)
{
	m_Position.x = startPosition.x;
	m_Position.y = startPosition.y;

	m_Gravity = gravity;

	m_Sprite.setPosition(m_Position);
}



FloatRect PlayableCharacter::getPosition()
{
	return m_Sprite.getGlobalBounds();
}
 
void PlayableCharacter::resolve_slope(float tileposition, int &slopenumber)
{ 
	if (slopenumber == 10)
	{
		if (m_vel.x > 0)


		{
			if (m_RightPressed)
			{
				m_Position.y = m_Position.y - (m_Position.x - m_oldposition.x);
				//m_Sprite.setRotation(10);
			}
			m_isFalling = false;

		}
 

		if (m_vel.x < 0)
		{
			if (m_LeftPressed)
			{
				m_Position.y = m_Position.y + (m_oldposition.x - m_Position.x);
			}
			m_isFalling = false;
		}

	}

	
	if (slopenumber == 28)
	{
		if (m_vel.x > 0)

			 
		{
			if (m_RightPressed)
			{
				m_Position.y = m_Position.y + (m_Position.x - m_oldposition.x);
				
			}
			m_isFalling = false;

		}


		if (m_vel.x < 0)
		{
			if (m_LeftPressed)
			{
				
				m_Position.y = m_Position.y - (m_oldposition.x - m_Position.x);
			}
			m_isFalling = false;
		}

	}


	
}

Vector2f PlayableCharacter::getCenter()
{
	return Vector2f(m_Position.x + m_Sprite.getGlobalBounds().width / 2,m_Position.y + m_Sprite.getGlobalBounds().height/2);
}

Vector2i PlayableCharacter::getTile_pos()
{
	FloatRect position;
	Vector2i tile_pos;
	
	position = PlayableCharacter::getPosition();
	tile_pos.x = (((int)position.left + (int)position.width) / TILE_SIZE);
	tile_pos.y = ((int)position.top / TILE_SIZE) + 1;
	return tile_pos;
}

Sprite PlayableCharacter::getSprite()
{
	return m_Sprite;
}

void PlayableCharacter::stopFalling(float position)
{
	//m_Position.y = position - getPosition().height;
	m_Sprite.setPosition(m_Position);
	m_isFalling = false;
}

void PlayableCharacter::stopRight(float position)
 
{
	m_Position.x = position - (m_Sprite.getGlobalBounds().width) ;
	//m_Sprite.setPosition(m_Position);
	
}

void PlayableCharacter::stopLeft(float position)
{
	m_Position.x = position;
	
}

void PlayableCharacter::stopJump()
{
	m_isJumping = false;

	// Gelöscht, weil bei 2 Steinen aufeinander sonst Character fällt
	//m_isFalling = true;
}


FloatRect PlayableCharacter::getFeet()
{
	return m_Feet;
}

FloatRect PlayableCharacter::getHead()
{
	return m_Head;
}

FloatRect PlayableCharacter::getLeft()
{
	return m_Left;
}

FloatRect PlayableCharacter::getRight()
{
	return m_Right;
}

FloatRect PlayableCharacter::get_Center()
{
	return m_Center;
}

void PlayableCharacter::set_objecttype(object_types otype) { m_otype = otype; }

object_types PlayableCharacter::get_objecttype() { return m_otype; }


void PlayableCharacter::set_maxlevelsize(int mlevelsize)
{
	m_maxlevelsize = mlevelsize;
}

int PlayableCharacter::get_maxlevelsize()
{
	return m_maxlevelsize;
}

void PlayableCharacter::set_leftslope_end(bool setend)
{
	m_leftslope_end = setend;
}

void PlayableCharacter::set_rightslope_end(bool setend)
{
	m_rightslope_end = setend;
}

void PlayableCharacter::set_iscollided(bool iscollided)
{

	m_iscollided = iscollided;

}

void PlayableCharacter::set_gravity(float gravity)
{
	m_Gravity = gravity;
}
