#include "stdafx.h"
#include "Engine.h"

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
			
		}
	}
	
}
