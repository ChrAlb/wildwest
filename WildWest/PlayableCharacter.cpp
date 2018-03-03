#include "stdafx.h"
#include "PlayableCharacter.h"
#include <iostream>

PlayableCharacter::PlayableCharacter() : m_id(0)
{
	
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
 
Vector2f PlayableCharacter::getCenter()
{
	return Vector2f(m_Position.x + m_Sprite.getGlobalBounds().width / 2,m_Position.y + m_Sprite.getGlobalBounds().height/2);
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

void PlayableCharacter::set_iscollided(bool iscollided)
{

	m_iscollided = iscollided;

}