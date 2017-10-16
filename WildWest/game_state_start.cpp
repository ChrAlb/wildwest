#include "stdafx.h"

#include <SFML\Graphics.hpp>

#include "game_state_start.h"
#include "Game_state.h"
#include "Game_state_game.h"

void GameStateStart::draw(const float dt)
{
	m_BackgroundSprite.setTexture(m_BackgroundTexture);
	
	this->game->window.setView(this->view);

	this->game->window.clear(sf::Color::White);
	
	this->game->window.draw(m_BackgroundSprite);

	return;
}

void GameStateStart::update(const float dt)
{

}

void GameStateStart::handleInput()
{
	sf::Event event;

	while (this->game->window.pollEvent(event))
	{
		switch (event.type)
		{
		case sf::Event::Closed:
		{
			game->window.close();
			break;
		}
		case sf::Event::Resized:
		{

		}
		case sf::Event::KeyPressed:
		{
			if (event.key.code == sf::Keyboard::Escape) this->game->window.close();
			else if (event.key.code == sf::Keyboard::Return) this->loadgame();
			break;
		}
	defautl: break;
		}
	}
	return;
}

GameStateStart::GameStateStart(Game* game)
{
	m_BackgroundTexture = TextureHolder::GetTexture("graphics/Title.png");
	this->game = game;
	sf::Vector2f pos = sf::Vector2f(this->game->window.getSize());
	this->view.setSize(pos);
	pos *= 0.5f;
	this->view.setCenter(pos);


}

void GameStateStart::loadgame()
{
	//game->popState();
	this->game->pushState(new GameStateGame(this->game)); 
}