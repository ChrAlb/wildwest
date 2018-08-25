/*

WildWest ist ein Plattformer Game, programmiert mit Visual Studio 2115, c++ und SFML

Autor: Christian Albrecht
Projektstart: Oktober 2017

Github:  https://github.com/ChrAlb/wildwest

*/

// WildWest.cpp : Definiert den Entry Point für die Console Applikation


#include "stdafx.h"
#include "game.h"
#include "game_state_start.h"
  
 
int main()
{
	Game game;
   
	srand(time(NULL));


	while (game.window.isOpen())
	{
		//game.HandleInput();
		game.Update();
		game.Render();
		game.LateUpdate();

	}
	
    
	return 0;
}


