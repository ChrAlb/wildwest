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
	FloatRect get_Center();

	Vector2f old_position;

	 
	Sprite getSprite();
	 
	void stopFalling(float position);
	void stopRight(float position);
	void stopLeft(float position);
	void stopJump();

	
	void set_objecttype(object_types otype);
	object_types get_objecttype();

	
	void resolve_slope45(float position);
	void set_leftslope_end(bool setend);
	void set_rightslope_end(bool setend);
	
	Vector2f getCenter();

	void set_maxlevelsize(int mlevelsize);
	int get_maxlevelsize();

	


	void set_iscollided(bool iscollided);

	void set_gravity(float gravity);


protected:
	Sprite m_Sprite;
	

	float m_JumpDuration;

	bool  m_isJumping;
	bool  m_isFalling;

	bool m_LeftPressed;
	bool m_RightPressed;

	bool m_leftslope_end;
	bool m_rightslope_end;

	float m_TimeThisJump;

	bool m_JustJumped;
	unsigned int m_id;

	float m_Gravity;
	float m_Speed = 300;
	Vector2f m_vel;

	Vector2i max_levelsize;

	Vector2f m_Position;

	Texture m_Texture;

	FloatRect m_Feet;
	FloatRect m_Head;
	FloatRect m_Right;
	FloatRect m_Left;
	FloatRect m_Center;

	object_types m_otype;

	int m_maxlevelsize;

	bool m_iscollided;

	Vector2f m_oldposition;
	
	sf::Vector2f dir = { 0.0f,0.0f };

	

};


