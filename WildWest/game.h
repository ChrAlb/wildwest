#pragma once

#include <stack>
#include "StateManager.h"

#include "LevelManager.h"


class Game
{

public:
	
	Game();
	~Game();

	Clock m_clock;
	Time m_elapsed;

	RenderWindow window;
	
	//void HandleInput();
	void Update();
	void Render();
	void LateUpdate();


private:
	StateManager m_stateManager;
};