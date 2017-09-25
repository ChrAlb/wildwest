#include "stdafx.h"
#include "Engine.h"
#include <iostream>

Engine::Engine()

{
	Vector2f resolution;
	resolution.x = VideoMode::getDesktopMode().width;
	resolution.y = VideoMode::getDesktopMode().height;
	
	m_Window.create(VideoMode(resolution.x,resolution.y),"WildWest",Style::Close);

	m_MainView.setSize(resolution);
	
	m_BackgroundTexture = TextureHolder::GetTexture("graphics/BG.png");
	m_BackgroundSprite.setTexture(m_BackgroundTexture);

	m_TextureTiles = TextureHolder::GetTexture("graphics/tiles_sheet.png");

}

void Engine::run()

{
	Clock clock;

	while (m_Window.isOpen())
	{
		Time dt = clock.restart();
		m_GameTimeTotal  += dt;
		float dtAsSeconds = dt.asSeconds();

		input();
		update(dtAsSeconds);
		draw();


	}
}