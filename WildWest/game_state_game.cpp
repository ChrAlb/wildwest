#include "stdafx.h"
#include <SFML\Graphics.hpp>

#include "Game_state.h"
#include "Game_state_game.h"
#include "game_state_start.h"
#include <iostream>
#include "LevelManager.h"


void GameStateGame::draw(const float dt)
{

	m_BackgroundSprite.setTexture(m_BackgroundTexture);

	this->game->window.clear(sf::Color::White);

	this->game->window.setView(bgview);
    this->game->window.draw(m_BackgroundSprite);
	
	this->game->window.setView(gameview);
	this->game->window.draw(m_VALevel, &m_TextureTiles);
	this->game->window.draw(m_player.getSprite());
	
    return;
}

void GameStateGame::update(const float dt)
{
	float newpos,move;
	LevelManager lm;
	
	if (m_newlevelrequiered)
	{
		oldpos = m_player.getCenter().x;
		oldpos = 150;
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
		
		newpos = m_player.getCenter().x;
		
		
		if ((oldpos == newpos) || (newpos < (VideoMode::getDesktopMode().width/2))  || (newpos> (m_VALevel.getBounds().width - (VideoMode::getDesktopMode().width / 2))))
		{
			move = 0;

		}
		else
		{
			move = newpos-oldpos;
		}
		oldpos = newpos;

		this->gameview.move(move,0);
		
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
	
	this->bgview.reset(sf::FloatRect(0, 0, VideoMode::getDesktopMode().width, VideoMode::getDesktopMode().height));
	this->gameview.reset(sf::FloatRect(0,0,VideoMode::getDesktopMode().width, VideoMode::getDesktopMode().height));
	
	 	
	
	

}