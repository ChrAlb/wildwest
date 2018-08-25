#include "stdafx.h"
#include "State_Intro.h"
#include "StateManager.h"

void State_Intro::LoadGame()
{
	m_music.stop();
}

void State_Intro::OnCreate()
{
	m_Textures.load(Textures::TitleScreen, "graphics/Title.png");

	m_music.play(Musik::Intro);

	sf::Vector2f pos = sf::Vector2f(window->getSize());
	view.setSize(pos);
	pos *= 0.5f;
	view.setCenter(pos);

}

void State_Intro::OnDestroy()
{

}

void State_Intro::Activate()
{
}

void State_Intro::Deactivate()
{
}

void State_Intro::HandleInput()
{
	sf::Event event;

	while (window->pollEvent(event))
	{
		switch (event.type)
		{
		case sf::Event::Closed:
		{
			window->close();
			break;
		}
		case sf::Event::Resized:
		{

		}
		case sf::Event::KeyPressed:
		{
			// Falls Esc-Taste => Spielabbruch;
			if (event.key.code == sf::Keyboard::Escape) window->close();
			// Falls Enter-Taste => Starte Lade Spiel (Game- Status , game-state-game)
			else if (event.key.code == sf::Keyboard::Return) LoadGame();
			break;
		}
		default: break;
		}
	}

	return;
}

void State_Intro::Update(const sf::Time & l_time)
{
	

}

void State_Intro::Draw()
{
	m_BackgroundSprite.setTexture(m_Textures.get(Textures::TitleScreen));

	window->setView(view);

	window->clear(sf::Color::White);

	window->draw(m_BackgroundSprite);

	return;
}
