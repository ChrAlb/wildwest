#include "stdafx.h"
#include <SFML\Graphics.hpp>

#include "Game_state.h"
#include "Game_state_game.h"
#include "game_state_start.h"
#include "game_state_end.h"
#include <iostream>
#include "LevelManager.h"
#include <list>
#include <string.h>

void GameStateGame::draw(const float dt)
{

	m_BackgroundSprite.setTexture(m_BackgroundTexture);
	m_Tree_Sprite.setTexture(m_Tree);
	m_Tree_Sprite.setPosition(Vector2f(1000, 700));

	this->game->window.clear(sf::Color::White);

	this->game->window.setView(bgview);
    this->game->window.draw(m_BackgroundSprite);
	
	this->game->window.setView(gameview);

	this->game->window.draw(m_Tree_Sprite);

	this->game->window.draw(m_VALevel, &m_TextureTiles);

	for (iter = objects.begin(); iter != objects.end(); ++iter)
	{
      this->game->window.draw((*iter)->getSprite());
	}
	
	this->game->window.draw(text);

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
	//LevelManager lm;
	
	if (m_LM.get_allLeveldone())
	{
		
		this->game->pushState(new GameStateEnd(this->game));
	}
		

	if (m_newlevelrequiered)
	{
		//oldpos = (*iter)->getCenter().x;
		//oldpos = 150;
		m_newlevelrequiered = false;
		loadLevel();
	}

	if (m_Playing)


		for (iter = objects.begin(); iter != objects.end(); ++iter)
		{
			

			{
				//(*iter)->update(dt);

				// DEBUG
				if (debug)
				{
									
					head_box.setSize(sf::Vector2f((*iter)->getHead().width, (*iter)->getHead().height));
					head_box.setOutlineColor(sf::Color::Red);
					head_box.setOutlineThickness(5);
					head_box.setPosition((*iter)->getHead().left, (*iter)->getHead().top);

					right_box.setSize(sf::Vector2f((*iter)->getRight().width, (*iter)->getRight().height));
					right_box.setOutlineColor(sf::Color::Green);
					right_box.setOutlineThickness(5);
					right_box.setPosition((*iter)->getRight().left, (*iter)->getRight().top);

					left_box.setSize(sf::Vector2f((*iter)->getLeft().width, (*iter)->getLeft().height));
					left_box.setOutlineColor(sf::Color::Blue);
					left_box.setOutlineThickness(5);
					left_box.setPosition((*iter)->getLeft().left, (*iter)->getLeft().top);

					feet_box.setSize(sf::Vector2f((*iter)->getFeet().width, (*iter)->getFeet().height));
					feet_box.setOutlineColor(sf::Color::Magenta);
					feet_box.setOutlineThickness(5);
					feet_box.setPosition((*iter)->getFeet().left, (*iter)->getFeet().top);

				}

				if (detectCollisions(*(*iter)))
				{
					if ((*iter)->get_objecttype() == t_Player)
					{
						m_newlevelrequiered = true;
						this->gameview.reset(sf::FloatRect(0, 0, VideoMode::getDesktopMode().width, VideoMode::getDesktopMode().height));

					}
				}
				(*iter)->update(dt);
						
				if ((*iter)->get_objecttype() == t_Player)
				{
					
					newpos = (*iter)->getCenter().x;


					if ((oldpos == newpos) || (newpos < (VideoMode::getDesktopMode().width / 2)) || (newpos > (m_VALevel.getBounds().width - (VideoMode::getDesktopMode().width / 2))))
					{
						move = 0;

					}
					else
					{
						move = newpos - oldpos;
					}
					oldpos = newpos;

					this->gameview.move(move, 0);
				}

			}
			
			if (debug)
			{
            text.setFont(m_font);
			text.setString("hello");
			text.setCharacterSize(24);
			text.setFillColor(sf::Color::Red);
			
			}
			


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

	for (iter = objects.begin(); iter != objects.end(); ++iter)
	{
    if ((*iter)->handleInput())
	  {
		;
	  }
	}

	
	return;
}

GameStateGame::GameStateGame(Game* game)
{
	
	m_font.loadFromFile("graphics/Arial.ttf");
	this->game = game;
	
	
}

