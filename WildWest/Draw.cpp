#include "stdafx.h"
#include "Engine.h"
#include <iostream>

void Engine::draw()

{
m_Window.clear(Color::White);
//m_Window.setView(m_BGMainView);
m_Window.draw(m_BackgroundSprite);
//m_Window.setView(m_MainView); 

m_Window.draw(m_VALevel, &m_TextureTiles);
m_Window.display();
}