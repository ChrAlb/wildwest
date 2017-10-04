#include "stdafx.h"
#include "Engine.h"
#include <SFML/Graphics.hpp>
#include <sstream>
#include <iostream>

void Engine::update(float dtAsSeconds)
{
	if (m_newlevelrequiered)
	{
		//m_player.spawn(Vector2f(500, 500), GRAVITY);
		//m_newlevelrequiered = false;
		loadLevel();
	}
	if (m_Playing)

	{



		m_player.update(dtAsSeconds);
		
		m_player.spawn(m_player.getm_Position(), GRAVITY);
	}


}

