#pragma once

#include <SFML\Graphics.hpp>

#include "Game_state.h"
#include "TextureHolder.h"

class GameStateEnd : public GameState
{
private:
	sf::View view;

	TextureHolder th;

	Sprite m_endSprite;
	Texture m_endTexture;

public:

	virtual void draw(const float dt);
	virtual void update(const float dt);
	virtual void handleInput();

	GameStateEnd(Game* game);
};


