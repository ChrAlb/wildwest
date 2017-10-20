// WildWest.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "game.h"
#include "game_state_start.h"
 
 
int main()
{
	Game game;
	game.pushState(new GameStateStart(&game));
	
	game.gameLoop();
	return 0;
}


