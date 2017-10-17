#pragma once

#include <stack>
#include <SFML\Graphics.hpp>
#include "TextureHolder.h"

#include "LevelManager.h"

class GameState;

class Game
{
private:

	//TextureHolder th;

	//LevelManager m_LM;

	//const int TILE_SIZE = 50;
	//const int VERTS_IN_QUAD = 4;

	//const int GRAVITY = 300;

	

	//Sprite m_BackgroundSprite;
	//Texture m_BackgroundTexture;

	//bool m_newlevelrequiered = true;
	//bool m_Playing = false;


	//VertexArray m_VALevel;

	//int** m_ArrayLevel = NULL;

	//Texture m_TextureTiles;

	//void loadLevel();

	//bool detectCollisions(PlayableCharacter& characters);


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