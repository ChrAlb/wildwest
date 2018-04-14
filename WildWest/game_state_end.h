#pragma once

#include <SFML\Graphics.hpp>

#include "Game_state.h"
#include "ResourceHolder.h"
#include "ResourceIdentifiers.h"

class GameStateEnd : public GameState
{
private:
	sf::View view;

	Sprite m_endSprite;
	
	TextureHolder m_Textures;

public:

	virtual void draw(const float dt);
	virtual void update(const float dt);
	virtual void handleInput();

	GameStateEnd(Game* game);
};


