#pragma once

#include <SFML\Graphics.hpp>

class Animation
{
public:
	Animation();
	void addFrame(sf::IntRect rect);
	void addRow(int x, int y, int width, int height, int maxframe);
	void ApplytoSprite(sf::Sprite& s);
	void Update(float dt);
	

private:
	void Advance();


private:
	static constexpr int nFrames = 8;
	static constexpr float holdtime = 0.1f;
	sf::Texture m_texture;

	std::vector<sf::IntRect> m_frames;
	
	float time = 0.0f;

	


};
