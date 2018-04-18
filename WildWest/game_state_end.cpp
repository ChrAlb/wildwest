#include "stdafx.h"

#include <SFML\Graphics.hpp>

#include "game_state_end.h"
#include "Game_state.h"
#include "Game_state_game.h"

void GameStateEnd::draw(const float dt)
{
	
	m_endSprite.setTexture(m_Textures.get(Textures::FinishLine));

	this->game->window.setView(this->view);

	this->game->window.clear(sf::Color::White);

	this->game->window.draw(m_endSprite);

	return;
}

void GameStateEnd::update(const float dt)
{

}

void GameStateEnd::handleInput()
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
			if (event.key.code == sf::Keyboard::Return) this->game->window.close();
			break;
		}
		default: break;
		}
	}

	return;
}

GameStateEnd::GameStateEnd(Game* game)
{
	
	
	this->game = game;
	m_Textures.load(Textures::FinishLine, "graphics/end.png");
	sf::Vector2f pos = sf::Vector2f(this->game->window.getSize());
	this->view.setSize(pos);
	pos *= 0.5f;
	this->view.setCenter(pos);


}
