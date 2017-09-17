#include "stdafx.h"
#include "Engine.h"

void Engine::draw()

{
m_Window.setView(m_BGMainView);
m_Window.draw(m_BackgroundSprite);
m_Window.setView(m_MainView);
m_Window.display();
}