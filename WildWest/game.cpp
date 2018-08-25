
#include "stdafx.h"

#include <stack>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

#include "game.h"
#include"Game_state.h"



Game::Game() : m_stateManager(&window)

{
	Vector2f resolution;
	resolution.x = VideoMode::getDesktopMode().width;
	resolution.y = VideoMode::getDesktopMode().height;

	window.create(sf::VideoMode(resolution.x, resolution.y), "Wild Wild West",Style::Close);
	window.setFramerateLimit(0);
	
	m_stateManager.SwitchTo(StateType::Intro);

}

Game::~Game()
{
	
}

void Game::Update()
{
	m_stateManager.Update(m_elapsed);
}

void Game::Render()
{
	m_stateManager.Draw();
}

void Game::LateUpdate()
{
	m_stateManager.ProcessRequests();
	m_elapsed = m_clock.restart();
}

