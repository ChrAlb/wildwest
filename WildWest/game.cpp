#include "stdafx.h"

#include <stack>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

#include "game.h"
#include"Game_state.h"

void Game::pushState(GameState* state)
{
	this->states.push(state);
	return;

}

void Game::popState()

{

	delete this->states.top();
	this->states.pop();

}

void Game::changeState(GameState* state)
{
	if (!this->states.empty())
		popState();
	pushState(state);

	return;
}

GameState* Game::peekState()
{
	if (this->states.empty()) return nullptr;
	return this->states.top();
}

void Game::gameLoop()
{
	sf::Clock clock;

	while (this-window.isOpen())
	{
		sf::Time elapsed = clock.restart();
		float dt = elapsed.asSeconds();

		if (peekState() == nullptr) continue;
		peekState()->handleInput();
		peekState()->update(dt);
		this->window.clear(sf::Color::White);
		peekState()->draw(dt);
		this->window.display();

	}
}

Game::Game()
{
	Vector2f resolution;
	resolution.x = VideoMode::getDesktopMode().width;
	resolution.y = VideoMode::getDesktopMode().height;

	this->window.create(sf::VideoMode(resolution.x, resolution.y), "Wild Wild West");
	this->window.setFramerateLimit(60);

	
	//m_TextureTiles = TextureHolder::GetTexture("graphics/tiles_sheet.png");


}

Game::~Game()
{
	while (!this->states.empty()) popState();
}

