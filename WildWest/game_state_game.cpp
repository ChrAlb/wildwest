#include "stdafx.h"
#include <SFML\Graphics.hpp>

#include "Game_state.h"
#include "Game_state_game.h"

void GameStateGame::draw(const float dt)
{
	m_BackgroundSprite.setTexture(m_BackgroundTexture);
	
	this->game->window.clear(sf::Color::White);
	this->game->window.draw(m_BackgroundSprite);

	return;
}

void GameStateGame::update(const float dt)
{
	return;
}

void GameStateGame::handleInput()
{
	sf::Event event;

	while (this->game->window.pollEvent(event))
	{
		switch (event.type)
		{
		case sf::Event::Closed:
		{
			this->game->window.close();
			break;
		}
		case sf::Event::Resized:
		{
			;
		}
		default: break;
		}
	}
	return;
}

GameStateGame::GameStateGame(Game* game)
{
	m_BackgroundTexture = TextureHolder::GetTexture("graphics/BG.png");
	this->game = game;
	sf::Vector2f pos = sf::Vector2f(this->game->window.getSize());
	this->gameview.setSize(pos);
	pos *= 0.5f;
	this->gameview.setCenter(pos);
}