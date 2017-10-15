#pragma once

#include <SFML\Graphics.hpp>

#include "Game_state.h"

class GameStateGame : public GameState
{
private:
	sf::View gameview;

public:

	virtual void draw(const float dt);
	virtual void update(const float dt);
	virtual void handleInput();

	GameStateGame(Game* game);
};
