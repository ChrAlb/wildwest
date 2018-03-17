#include "stdafx.h"
#include "game.h"
#include <iostream>
#include "Game_state_game.h"

bool GameStateGame::detectCollisions(PlayableCharacter& character)

{
FloatRect position;
int       tilex,tiley;
float    deltatobottom;


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
			
			 if (
				 (m_ArrayLevel[y][x] == 10) ||
				 (m_ArrayLevel[y][x] == 27)
			    )
			 {
				 if (
					character.get_Center().intersects(block)
				    )
				 {
					 
					 position = character.getPosition();
    				 tilex = (((int)position.left + (int)position.width) / TILE_SIZE);
					 tiley = ((int)position.top / TILE_SIZE) + 1;


					 if (!m_ArrayLevel[tiley+1][tilex-1] == 10)
					 {
						 character.set_leftslope_end(true);
						 deltatobottom = position.top - position.height - y*TILE_SIZE;
	                 } else

/*					 if (!m_ArrayLevel[tiley + 1][tilex + 1] == 10)
					 {
						 character.set_rightslope_end(true);
						 deltatobottom = position.top - position.height - y*TILE_SIZE;
					 } else  */
					 {
						 deltatobottom = 0;
					 }

                     character.resolve_slope45(0);
				 }
			 }
			 else


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

		} // end for
	}  // end for
	return reachedGoal;
}



