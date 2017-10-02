#include "stdafx.h"
#include "Engine.h"
#include <SFML/Graphics.hpp>
#include <sstream>

void Engine::update(float dtAsSeconds)
{

if (m_NewLevelRequiered)
{
	//m_player.spawn(Vector2f(0, 0), GRAVITY);
	loadLevel();
	if (m_Playing)
		m_player.update(dtAsSeconds);
}
}

