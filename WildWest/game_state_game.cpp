#include "stdafx.h"
#include <SFML\Graphics.hpp>

#include "Game_state.h"
#include "Game_state_game.h"
#include "game_state_start.h"
#include <iostream>


void GameStateGame::draw(const float dt)
{
	m_BackgroundSprite.setTexture(m_BackgroundTexture);
	
	this->game->window.clear(sf::Color::White);
	this->game->window.setView(gameview);
	this->game->window.draw(m_BackgroundSprite);
	this->game->window.draw(m_VALevel, &m_TextureTiles);
	this->game->window.draw(m_player.getSprite());
	
    return;
}

void GameStateGame::update(const float dt)
{
	if (m_newlevelrequiered)
	{
		m_player.spawn(Vector2f(500, 500), GRAVITY);
		m_newlevelrequiered = false;
		loadLevel();
	}

	if (m_Playing)

	{
		m_player.update(dt);


		if (detectCollisions(m_player))
		{
			m_newlevelrequiered = true;
		}

		m_player.spawn(m_player.getm_Position(), GRAVITY);
		this->gameview.setCenter(m_player.getCenter());
		//cout << m_player.getCenter().x << "  ";
		//cout << m_player.getCenter().y << "  ";


	}
	
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
		
		
		default: break;
		}

	}
	
	m_Playing = true;

	if (m_player.handleInput())
	{
		;
	}
	
	return;
}

GameStateGame::GameStateGame(Game* game)
{
	m_BackgroundTexture = TextureHolder::GetTexture("graphics/BG.png");
	m_TextureTiles = TextureHolder::GetTexture("graphics/tiles_sheet.png");
	this->game = game;
    
	this->gameview.setSize(VideoMode::getDesktopMode().width,VideoMode::getDesktopMode().height);
	this->gameview.setCenter(m_player.getCenter());
	
	//pos = m_player.getCenter(); 
	//sf::Vector2f pos = sf::Vector2f(this->game->window.getSize());
	
	//this->gameview.setSize(pos);
	//pos *= 0.5f; 
	
	
	//this->gameview.setCenter(pos);
	//cout << m_player.getCenter().x << "  ";
	//cout << m_player.getCenter().y << "  ";

}