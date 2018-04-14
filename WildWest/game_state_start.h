#pragma once
#include <SFML\Graphics.hpp>

#include "Game_state.h"
#include "ResourceHolder.h"
#include "ResourceIdentifiers.h"

class GameStateStart : public GameState
{
private:
	sf::View view;

	void loadgame();

	Sprite m_BackgroundSprite;
	
	TextureHolder m_Textures;

public:

	virtual void draw(const float dt);
	virtual void update(const float dt);
	virtual void handleInput();

	GameStateStart(Game* game);
};


