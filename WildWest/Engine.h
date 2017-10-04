#pragma once
#include <SFML/Graphics.hpp>
#include "TextureHolder.h"
#include "Player.h"
#include"LevelManager.h"

using namespace sf;

class Engine
{
private:
	TextureHolder th;

	Player m_player;

	const int TILE_SIZE = 50;
	const int VERTS_IN_QUAD = 4;

	const int GRAVITY = 300;

	RenderWindow m_Window;

	Sprite m_BackgroundSprite;
	Texture m_BackgroundTexture;

	bool m_newlevelrequiered = true;
	bool m_Playing = false;

	
	//VertexArray m_VALevel;

	int** m_ArrayLevel = NULL;

	//Texture m_TextureTiles;

    void input();
	void update(float dtAsSeconds);
	void draw();

	void loadLevel();

public:

	Engine();

	void run();

};


