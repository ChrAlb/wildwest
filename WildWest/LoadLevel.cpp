#include "stdafx.h"
#include "game.h"
#include "Game_state_game.h"
//#include "Player.h"
//#include  "PlayableCharacter.h"

void GameStateGame::loadLevel()

{

	m_Playing = false;

	for (int i = 0; i < m_LM.getLevelSize().y; ++i)
	{
		delete[] m_ArrayLevel[i];
	}
	delete[] m_ArrayLevel;

	m_ArrayLevel = m_LM.nextLevel(m_VALevel);
	m_player.spawn(m_LM.getStartPosition(),GRAVITY);m_BackgroundTexture = TextureHolder::GetTexture("graphics/BG.png");
	m_TextureTiles = TextureHolder::GetTexture("graphics/tiles_sheet.png");
	m_Tree = TextureHolder::GetTexture("graphics/Tree.png");

	this->bgview.reset(sf::FloatRect(0, 0, VideoMode::getDesktopMode().width, VideoMode::getDesktopMode().height));
	this->gameview.reset(sf::FloatRect(0, 0, VideoMode::getDesktopMode().width, VideoMode::getDesktopMode().height));


	m_newlevelrequiered = false;

}