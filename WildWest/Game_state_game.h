#pragma once

#include <SFML\Graphics.hpp>

#include "Game_state.h"
#include "TextureHolder.h"

class GameStateGame : public GameState
{
private:
	sf::View gameview;

    TextureHolder th;
	Sprite m_BackgroundSprite;
	Texture m_BackgroundTexture;

public:

	virtual void draw(const float dt);
	virtual void update(const float dt);
	virtual void handleInput();

	GameStateGame(Game* game);
};
