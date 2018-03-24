#include "stdafx.h"
#include "game.h"
#include <iostream>
#include "Game_state_game.h"

bool GameStateGame::detectCollisions(PlayableCharacter& character)

{
FloatRect position;


bool reachedGoal = false;
FloatRect detecionZone = character.getPosition();
	
	
//Debug
if (debug)
{
    box_position.setSize(sf::Vector2f(detecionZone.width, detecionZone.height));
    box_position.setOutlineColor(sf::Color::Black);
    box_position.setOutlineThickness(3);
    box_position.setFillColor(sf::Color(255, 0, 0, 0));
    box_position.setPosition(detecionZone.left, detecionZone.top);
}

FloatRect block;

block.width = TILE_SIZE;
block.height = TILE_SIZE;

int startX = (int)(detecionZone.left / TILE_SIZE - 1);
int startY = (int)(detecionZone.top / TILE_SIZE - 1);
int endX = (int)(detecionZone.left / TILE_SIZE + 3);
int endY = (int)(detecionZone.top / TILE_SIZE + 3);

		
if (startX < 0)startX = 0;
if (startY < 0)startY = 0;
if (endX >= m_LM.getLevelSize().x)endX = m_LM.getLevelSize().x;
if (endY >= m_LM.getLevelSize().y)endY = m_LM.getLevelSize().y;

FloatRect level(0, 0, m_LM.getLevelSize().x * TILE_SIZE, m_LM.getLevelSize().y * TILE_SIZE);


if (!character.getPosition().intersects(level))
{
	if (character.get_objecttype() == t_Player)
	{
		character.spawn(m_LM.getStartPosition(), GRAVITY);
		this->gameview.reset(sf::FloatRect(0, 0, VideoMode::getDesktopMode().width, VideoMode::getDesktopMode().height));
	}
}


for (int x = startX; x < endX; x++)
{
	for (int y = startY; y < endY; y++)
		{
		
			block.left = x * TILE_SIZE;
			block.top = y * TILE_SIZE;

			//********** DEBUG

			if (debug)
			{
				box.setSize(sf::Vector2f((endX - startX)*TILE_SIZE, (endY - startY)*TILE_SIZE));
				box.setFillColor(sf::Color(255, 0, 255, 50));
				box.setPosition(block.left - ((endX - startX)*TILE_SIZE) + 2 * TILE_SIZE, block.top - ((endY - startY)*TILE_SIZE) + TILE_SIZE);
			}
			//**************

			
			
				if ((m_ArrayLevel[y][x] == 10))
				{
					if (character.get_Center().intersects(block))
					{
						if (!character.m_on_slope)
						{
							character.m_on_slope = true;
							position = character.getPosition();
							character.slope_index.x = (((int)position.left + (int)position.width) / TILE_SIZE);
							character.slope_index.y = ((int)position.top / TILE_SIZE) + 1;

						}
						else


						{
							if (character.m_vel.x > 0)
							{
								if (m_ArrayLevel[character.slope_index.y - 1][character.slope_index.x + 1] == 10)
								{
									character.m_on_slope = true;
									character.slope_index = { character.slope_index.y - 1, character.slope_index.x + 1 };
								}
								else
									character.m_on_slope = false;
							}
							else if (character.m_vel.x < 0)
							{
								if (m_ArrayLevel[character.slope_index.y + 1][character.slope_index.x - 1] == 10)
								{
									character.m_on_slope = true;
									character.slope_index = { character.slope_index.y + 1, character.slope_index.x - 1 };
								}
								else
									character.m_on_slope = false;
							}


						}
						character.resolve_slope45(0);

					}
				}
			   
			// else

			{

				if (

					(m_ArrayLevel[y][x] == 0) ||
					(m_ArrayLevel[y][x] == 7) ||
					(m_ArrayLevel[y][x] == 8) ||
					(m_ArrayLevel[y][x] == 9) ||
					(m_ArrayLevel[y][x] == 14) ||
					(m_ArrayLevel[y][x] == 15) ||
					(m_ArrayLevel[y][x] == 16) ||
					(m_ArrayLevel[y][x] == 17) ||
					(m_ArrayLevel[y][x] == 18) ||
					(m_ArrayLevel[y][x] == 19) ||
					(m_ArrayLevel[y][x] == 23) ||
					(m_ArrayLevel[y][x] == 24)
					)

				{
					if (character.getRight().intersects(block))
					{
						character.stopRight(block.left);
						character.set_iscollided(true);

					}
					else
						if (character.getLeft().intersects(block))
						{
							character.stopLeft(block.left + TILE_SIZE);
							character.set_iscollided(true);
						}

					if (character.getFeet().intersects(block))
					{
						character.stopFalling(block.top);
					}
					else
						if (character.getHead().intersects(block))
						{
							character.stopJump();
						}

				}


				// LevelEnd Reached (Tile #2)
				if (m_ArrayLevel[y][x] == 2)
				{
					reachedGoal = true;
				}
			}
		} // end for
	}  // end for
	return reachedGoal;
}



