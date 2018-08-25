#pragma once

#include <stack>
#include <SFML\Graphics.hpp>
#include "StateManager.h"

#include "LevelManager.h"


class Game
{

public:
	
	Game();
	~Game();

	std::stack<GameState*> states;

	RenderWindow window;

	sf::Clock m_clock;
	sf::Time m_elapsed;

	

	//void HandleInput();
	void Update();
	void Render();
	void LateUpdate();


private:

	StateManager m_stateManager;
};