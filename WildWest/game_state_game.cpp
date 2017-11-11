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

    // DEBUG
	if (debug)
	{
		this->game->window.draw(head_box);
		this->game->window.draw(right_box);
		this->game->window.draw(left_box);
		this->game->window.draw(feet_box);
		this->game->window.draw(box);
		
		this->game->window.draw(box_position);
		// DEBUNG End
	}

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

        // DEBUG
		if (debug)
		{
			head_box.setSize(sf::Vector2f(m_player.getHead().width, m_player.getHead().height));
			head_box.setOutlineColor(sf::Color::Red);
			head_box.setOutlineThickness(5);
			head_box.setPosition(m_player.getHead().left, m_player.getHead().top);

			right_box.setSize(sf::Vector2f(m_player.getRight().width, m_player.getRight().height));
			right_box.setOutlineColor(sf::Color::Green);
			right_box.setOutlineThickness(5);
			right_box.setPosition(m_player.getRight().left, m_player.getRight().top);

			left_box.setSize(sf::Vector2f(m_player.getLeft().width, m_player.getLeft().height));
			left_box.setOutlineColor(sf::Color::Blue);
			left_box.setOutlineThickness(5);
			left_box.setPosition(m_player.getLeft().left,m_player.getLeft().top);

			feet_box.setSize(sf::Vector2f(m_player.getFeet().width, m_player.getFeet().height));
			feet_box.setOutlineColor(sf::Color::Magenta);
			feet_box.setOutlineThickness(5);
			feet_box.setPosition(m_player.getFeet().left, m_player.getFeet().top);

		}
		// DEBUG End



		m_player.getHead().top;

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