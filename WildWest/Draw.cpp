#include "stdafx.h"
#include "Engine.h"
#include <iostream>

void Engine::draw()

{
m_Window.clear(Color::White);

m_Window.draw(m_BackgroundSprite);



m_Window.display();

}