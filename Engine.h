#pragma once
#include <SFML/Graphics.hpp>
#include "TextureHolder.h"

using namespace sf;

class Engine
{
private:
	TextureHolder th;

	const int TILE_SIZE = 50;
	const int VERTS_IN_QUAD = 4;

	const int GRAVITY = 300;

	RenderWindow m_Window;

	View m_MainView;
	View m_BGMainView;

	Sprite m_BackgroundSprite;
	Texture m_BackgroundTexture;

	bool m_Playing = false;

	bool m_NewLevelRequiered = true;

	Time m_GameTimeTotal;

	void input();
	void update(float dtAsSeconds);
	void draw();

public:

	Engine();

	void run();


};


