#include "stdafx.h"
#include "game.h"
#include <iostream>
#include "Game_state_game.h"

bool GameStateGame::detectSlope(PlayableCharacter & character)

{
	FloatRect position;
	int       x, y;
	bool      on_slope;


	on_slope = false;
	position = character.getPosition();
	x = (( (int)position.left + (int)position.width) / TILE_SIZE) - 1;
	y = ( (int)position.top / TILE_SIZE) + 1;

	// Warum wird y hier in gamestate hochgezählt?
	if (y >= m_LM.getLevelSize().y)
		 y = 0;

	if (   (m_ArrayLevel[y][x] == 10)  || (m_ArrayLevel[y][x] == 11)  || (m_ArrayLevel[y][x] == 12)   )

	{
		on_slope = true;
	}

	return on_slope;
}

void GameStateGame::resolveSlope(PlayableCharacter & character)
{
	;
}
