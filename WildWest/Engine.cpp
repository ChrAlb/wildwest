#include "stdafx.h"
#include "Engine.h"

Engine::Engine()

{
	Vector2f resolution;
	resolution.y = VideoMode::getDesktopMode().width;
	resolution.x = VideoMode::getDesktopMode().height;

	m_Window.create(VideoMode(resolution.x, resolution.y), "Wild Wild West", Style::Fullscreen);

	m_MainView.setSize(resolution);

	m_BackgroundTexture = TextureHolder::GetTexture("graphics/BG.png");
	m_BackgroundSprite.setTexture(m_BackgroundTexture);

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