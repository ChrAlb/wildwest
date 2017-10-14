#include "stdafx.h"
#include "game.h"
#include <iostream>

bool Game::detectCollisions(PlayableCharacter& character)

{
	bool reachedGoal = false;
	FloatRect detecionZone = character.getPosition();

	FloatRect block;

	block.width = TILE_SIZE;
	block.height = TILE_SIZE;

	int startX = (int)(detecionZone.left / TILE_SIZE - 1);
	int startY = (int)(detecionZone.top / TILE_SIZE - 1);
	int endX = (int)(detecionZone.left / TILE_SIZE + 2);
	int endY = (int)(detecionZone.top / TILE_SIZE + 3);


	if (startX < 0)startX = 0;
	if (startY < 0)startY = 0;
	if (endX >= m_LM.getLevelSize().x)endX = m_LM.getLevelSize().x;
	if (endY >= m_LM.getLevelSize().y)endY = m_LM.getLevelSize().y;

	FloatRect level(0, 0, m_LM.getLevelSize().x * TILE_SIZE, m_LM.getLevelSize().y * TILE_SIZE);

	
	if (!character.getPosition().intersects(level))
	{
		character.spawn(m_LM.getStartPosition(), GRAVITY);
	}
	

	for (int x = startX; x < endX ;  x++)
	{
		for (int y = startY ; y < endY; y++)
		{
			block.left = x * TILE_SIZE;
			block.top = y * TILE_SIZE;

		
			if (m_ArrayLevel[y][x] == 0)
			{
				if (character.getRight().intersects(block))
				{
					character.stopRight(block.left);
				}
				else if (character.getLeft().intersects(block))
				{
					character.stopLeft(block.left);
				}
				if (character.getFeet().intersects(block))
				{
					character.stopFalling(block.top);
				} 
				else if (character.getHead().intersects(block))
				{
					character.stopJump();
				}

			}

			if (m_ArrayLevel[y][x] == 1)
			{
				reachedGoal = true;
			}

		}
	}
	return reachedGoal;
}



