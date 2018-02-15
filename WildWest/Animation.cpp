#include "stdafx.h"
#include "Animation.h"
#include "TextureHolder.h"

Animation::Animation()
{
	m_texture = TextureHolder::GetTexture("graphics/joe_sheet.png");
	
}

void Animation::addFrame(sf::IntRect rect)
{
	m_frames.push_back(rect);
}

void Animation::addRow(int x, int y, int width,int height,int maxframe)
{
	for (int i = 0; i < maxframe; i++)
	{
		addFrame({ x + i*width, y,width, height });		
	}
}

void Animation::ApplytoSprite(sf::Sprite& s)
{
	s.setTexture(m_texture);
	s.setTextureRect(m_frames[iFrame]);
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

	
void Animation::Advance()
{
	
	if (++iFrame >= sizeof(m_frames))
	{
		iFrame = 0;
	}
	
}
