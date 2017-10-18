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
	
	m_player.spawn(m_LM.getStartPosition(),GRAVITY);

	m_newlevelrequiered = false;

}