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




// Delete alle Objekte und ArrayLevel

	for (iter = objects.begin(); iter != objects.end();)
	{
		delete (*iter);
		iter = objects.erase(iter);
		
	}
	

	
	for (int i = 0; i < m_LM.getLevelSize().y; ++i)
	{
		delete[] m_ArrayLevel[i];
	}
	delete[] m_ArrayLevel;
// EndDelete


	m_ArrayLevel = m_LM.nextLevel(m_VALevel, leveldata);
	
	player = new Player();
    player->spawn(m_LM.getStartPosition(), GRAVITY); 
	m_BackgroundTexture = TextureHolder::GetTexture(leveldata.BGFileName);

	int maxlevelsize = (m_LM.getLevelSize().x * TILE_SIZE) - TILE_SIZE;

	player->set_objecttype(t_Player);
	player->set_maxlevelsize(maxlevelsize);

	objects.push_back(player);

/*
	enemy = new Enemy();
	Vector2f ll;
	ll.x = 2200;
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