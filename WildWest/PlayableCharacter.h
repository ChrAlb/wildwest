#pragma once
#include <SFML\Graphics.hpp>

using namespace sf;

class PlayableCharacter
{
protected:
	Sprite m_Sprite;

	float m_JumpDuration;

	bool  m_isJumping;
	bool  m_isFalling;

	bool m_LeftPressed;
	bool m_RightPressed;

	float m_TimeThisJump;

	bool m_JustJumped;

private:

	float m_Gravity;
	float m_Speed = 400;

	Vector2f m_Position;

	Texture m_Texture;

public:

	void spawn(Vector2f startPosition, float gravity);
	bool virtual handleInput() = 0;

	FloatRect getPosition();

	Sprite getSprite();

	void stopFalling(float position);
	void stopRight(float position);
	void stopLeft(float position);
	void stopJump();

	Vector2f getCenter();

	void update(float elapsedtime);
};
