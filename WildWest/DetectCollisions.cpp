#include "stdafx.h"
#include "game.h"
#include <iostream>
#include "Game_state_game.h"

bool GameStateGame::detectCollisions(PlayableCharacter& character)

{
	bool reachedGoal = false;
	FloatRect detecionZone = character.getPosition();
	//Debug
	
	if (debug)
	{
    box_position.setSize(sf::Vector2f(TILE_SIZE*2, TILE_SIZE*2));
	box_position.setOutlineColor(sf::Color::Black);
	box_position.setOutlineThickness(5);
	box_position.setFillColor(sf::Color(255, 255, 255, 128));
	box_position.setPosition(detecionZone.left,detecionZone.top);
	}
	

	FloatRect block;

	block.width = TILE_SIZE;
	block.height = TILE_SIZE;

	int startX = (int)(detecionZone.left / TILE_SIZE - 1);
	int startY = (int)(detecionZone.top / TILE_SIZE -1);
	int endX = (int)(detecionZone.left / TILE_SIZE + 2);
	int endY = (int)(detecionZone.top / TILE_SIZE + 3);

    //cout << startX << "    " << startY << "   ";
	//cout << endX << "    " << endY << "   "; 
	if (startX < 0)startX = 0;
	if (startY < 0)startY = 0;
	if (endX >= m_LM.getLevelSize().x)endX = m_LM.getLevelSize().x;
	if (endY >= m_LM.getLevelSize().y)endY = m_LM.getLevelSize().y;

	FloatRect level(0, 0, m_LM.getLevelSize().x * TILE_SIZE, m_LM.getLevelSize().y * TILE_SIZE);
	

	
	
	if (!character.getPosition().intersects(level))
	{
		character.spawn(m_LM.getStartPosition(), GRAVITY);
		this->gameview.reset(sf::FloatRect(0, 0, VideoMode::getDesktopMode().width, VideoMode::getDesktopMode().height));
	}
	
	//cout << m_ArrayLevel[20][7];

	for (int x = startX; x < endX ;  x++)
	{
		for (int y = startY ; y < endY; y++)
		{
			block.left = x * TILE_SIZE;
			block.top = y * TILE_SIZE;
			
			//********** DEBUG
			if (debug)
			{
            box.setSize(sf::Vector2f((endX-startX)*TILE_SIZE,(endY-startY)*TILE_SIZE));
			box.setOutlineColor(sf::Color::White);
			box.setOutlineThickness(5);
			box_position.setFillColor(sf::Color(255, 255, 255, 128));
			box.setPosition(block.left,block.top);
			}
			//**************

			
		
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



