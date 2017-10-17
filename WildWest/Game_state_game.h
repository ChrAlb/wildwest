#pragma once

#include <SFML\Graphics.hpp>

#include "Game_state.h"
#include "TextureHolder.h"
#include "PlayableCharacter.h"

class GameStateGame : public GameState
{
private:
	sf::View gameview;

    TextureHolder th;
	Sprite m_BackgroundSprite;
	Texture m_BackgroundTexture;

	LevelManager m_LM;

	const int TILE_SIZE = 50;
	const int VERTS_IN_QUAD = 4;

	const int GRAVITY = 300;

	bool m_newlevelrequiered = true;
	bool m_Playing = false;


	VertexArray m_VALevel;

	int** m_ArrayLevel = NULL;

	Texture m_TextureTiles;

	void loadLevel();

	bool detectCollisions(PlayableCharacter& characters);



public:

	virtual void draw(const float dt);
	virtual void update(const float dt);
	virtual void handleInput();

	GameStateGame(Game* game);
};
