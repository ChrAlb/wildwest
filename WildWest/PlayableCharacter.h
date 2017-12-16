#pragma once
#include <SFML\Graphics.hpp>

using namespace sf;

class PlayableCharacter
	
{
	friend class EntityManager;

public:

	PlayableCharacter();
	void spawn(Vector2f startPosition, float gravity);
	bool virtual handleInput() = 0;
	void virtual update(float dt) = 0;

	FloatRect getPosition();

	FloatRect getFeet();
	FloatRect getHead();
	FloatRect getRight();
	FloatRect getLeft();

	Sprite getSprite();

	void stopFalling(float position);
	void stopRight(float position);
	void stopLeft(float position);
	void stopJump();


	Vector2f getCenter();

	//void update(float elapsedtime);

protected:
	Sprite m_Sprite;
	Sprite m_Enemy;

	float m_JumpDuration;

	bool  m_isJumping;
	bool  m_isFalling;

	bool m_LeftPressed;
	bool m_RightPressed;

	float m_TimeThisJump;

	bool m_JustJumped;
	unsigned int m_id;

	float m_Gravity;
	float m_Speed = 400;

	Vector2f m_Position;

	Texture m_Texture;

	FloatRect m_Feet;
	FloatRect m_Head;
	FloatRect m_Right;
	FloatRect m_Left;



};


