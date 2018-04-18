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


	m_ArrayLevel = m_LM.nextLevel(m_VALevel, m_leveldaten);

	// Load Textures
	if (!m_LM.get_allLeveldone())
	     m_Textures.load(m_leveldaten.m_bg_texture, m_leveldaten.BGFileName);
	//m_Textures.load(Textures::Tiles, m_leveldaten.TilSetName);
	//m_Textures.load(Textures::Tree, "graphics/Tree.png");
	
	// end Load Textures
	
	
    player = new Player();
    player->spawn(m_LM.getStartPosition(), GRAVITY); 
	

	int maxlevelsize = (m_LM.getLevelSize().x * TILE_SIZE) - TILE_SIZE;

	player->set_objecttype(t_Player);
	player->set_maxlevelsize(maxlevelsize);
	player->set_iscollided(false);    
	objects.push_back(player);

/*
	enemy = new Enemy();
	Vector2f startpoint;
	startpoint.x = 800;
	startpoint.y = 700;
	enemy->spawn(startpoint,GRAVITY);
	
	enemy->set_objecttype(t_Enemy);
	enemy->set_maxlevelsize(maxlevelsize);
	enemy->set_iscollided(false);
	objects.push_back(enemy);
*/	
	

	
	this->bgview.reset(sf::FloatRect(0, 0, VideoMode::getDesktopMode().width, VideoMode::getDesktopMode().height));
	this->gameview.reset(sf::FloatRect(0, 0, VideoMode::getDesktopMode().width, VideoMode::getDesktopMode().height));


	m_newlevelrequiered = false;

}