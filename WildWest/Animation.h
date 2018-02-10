#pragma once

#include <SFML\Graphics.hpp>

class Animation
{
public:
	Animation() = default;
	Animation(int x, int y, int width, int height);
	void ApplytoSprite(sf::Sprite& s);
	void Update(float dt);
	void Go();
	void Stop();

private:
	void Advance();


private:
	static constexpr int nFrames = 8;
	static constexpr float holdtime = 0.1f;
	sf::Texture m_texture;
	sf::IntRect frames[nFrames];
	int iFrame = 0;
	float time = 0.0f;

	bool animation_stop = false;


};
