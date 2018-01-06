#pragma once
#include <SFML\Graphics.hpp>

using namespace sf;

enum object_types { t_Player, t_Enemy, t_Others };

class PlayableCharacter
	
{
	//friend class EntityManager;

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

	void right_slopeup();
	void left_slopeup();

	void set_objecttype(object_types otype);
	object_types get_objecttype();

	
	Vector2f getCenter();

	void set_maxlevelsize(int mlevelsize);
	int get_maxlevelsize();


protected:
	Sprite m_Sprite;
	

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

	Vector2i max_levelsize;

	Vector2f m_Position;

	Texture m_Texture;

	FloatRect m_Feet;
	FloatRect m_Head;
	FloatRect m_Right;
	FloatRect m_Left;

	object_types m_otype;

	int m_maxlevelsize;

};


