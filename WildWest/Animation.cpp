#include "stdafx.h"
#include "Animation.h"
#include "TextureHolder.h"

Animation::Animation(int x, int y, int width, int height)
{
	m_texture = TextureHolder::GetTexture("graphics/joe_sheet.png");
	for (int i = 0; i < nFrames; i++)
	{
		frames[i] = { x + i*width, y,width, height };
    }
}

void Animation::ApplytoSprite(sf::Sprite& s)
{
	s.setTexture(m_texture);
	s.setTextureRect(frames[iFrame]);
}

void Animation::Update(float dt)
{
	time += dt;
	while (time >= holdtime)
	{
		time -= holdtime;
		//if (!animation_stop)
		   Advance();
	}
}

void Animation::Go()
{
	animation_stop = false;
}

void Animation::Stop()
{
	animation_stop = true;
}


	

void Animation::Advance()
{

		if (++iFrame >= nFrames)
		{
			iFrame = 0;
		}
	
	
}
