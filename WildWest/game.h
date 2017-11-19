#pragma once

#include <stack>
#include <SFML\Graphics.hpp>
#include "TextureHolder.h"

#include "LevelManager.h"

class GameState;

class Game
{
private:

public:
	
	std::stack<GameState*> states;

	RenderWindow window;

	void pushState(GameState* state);
	void popState();
	void changeState(GameState* state);
	GameState* peekState();

	void gameLoop();

	Game();
	~Game();
};