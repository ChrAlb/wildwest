#include "stdafx.h"
#include "Engine.h"
#include <iostream>

void Engine::input()

{
	Event event;

	while (m_Window.pollEvent(event))
	{
		if (event.type == Event::KeyPressed)
		{
			if (Keyboard::isKeyPressed(Keyboard::Escape))
			{
				m_Window.close();
			}
			if (Keyboard::isKeyPressed(Keyboard::Return))
			{
				m_Playing = true;
			}
			
		}

	}
	if (m_player.handleInput())
	{
            ;
	}
		
}
