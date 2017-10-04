#include "stdafx.h"
#include "Engine.h"
#include <iostream>

void Engine::draw()

{
m_Window.clear(Color::White);

m_Window.draw(m_BackgroundSprite);

m_Window.draw(m_VALevel, &m_TextureTiles);

m_Window.draw(m_player.getSprite());

m_Window.display();

}
