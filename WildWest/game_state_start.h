#pragma once
#include <SFML\Graphics.hpp>

#include "Game_state.h"
#include "TextureHolder.h"

class GameStateStart : public GameState
{
private:
	sf::View view;
	TextureHolder th;

	Sprite m_BackgroundSprite;
	Texture m_BackgroundTexture;

public:

	virtual void draw(const float dt);
	virtual void update(const float dt);
	virtual void handleInput();

	GameStateStart(Game* game);
};


