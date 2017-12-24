#include "stdafx.h"
#include "game.h"
#include "Game_state_game.h"
#include <iostream>
//#include "EntityManager.h"

//#include "Player.h"
//#include  "PlayableCharacter.h"

void GameStateGame::loadLevel()

{
	
	m_Playing = false;
	leveldate leveldata;

	for (int i = 0; i < m_LM.getLevelSize().y; ++i)
	{
		delete[] m_ArrayLevel[i];
	}
	delete[] m_ArrayLevel;

	

	m_ArrayLevel = m_LM.nextLevel(m_VALevel, leveldata);
	
	player = new Player();
    player->spawn(m_LM.getStartPosition(), GRAVITY); 
	m_BackgroundTexture = TextureHolder::GetTexture(leveldata.BGFileName);
	player->set_objecttype(t_Player);
	objects.push_back(player);

	/*
	enemy = new Enemy();
	Vector2f ll;
	ll.x = 200;
	ll.y = 500;
	enemy->spawn(ll,GRAVITY);
	//m_BackgroundTexture = TextureHolder::GetTexture(leveldata.BGFileName);
	enemy->set_objecttype(t_Enemy);
	objects.push_back(enemy);
	*/
	m_TextureTiles = TextureHolder::GetTexture(leveldata.TilSetName);
	m_Tree = TextureHolder::GetTexture("graphics/Tree.png");

	this->bgview.reset(sf::FloatRect(0, 0, VideoMode::getDesktopMode().width, VideoMode::getDesktopMode().height));
	this->gameview.reset(sf::FloatRect(0, 0, VideoMode::getDesktopMode().width, VideoMode::getDesktopMode().height));


	m_newlevelrequiered = false;

}