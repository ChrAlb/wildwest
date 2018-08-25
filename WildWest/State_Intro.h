#pragma once
#include "BaseState.h"
#include "MusicPlayer.h"

class State_Intro : public BaseState 
{
public:

	

	void OnCreate();
	void OnDestroy();

	void Activate();
	void Deactivate();

	void HandleInput();
	void Update(const sf::Time& l_time);
	void Draw();

	void LoadGame();

private:
    RenderWindow* window;
	sf::View view;
	Sprite m_BackgroundSprite;
    TextureHolder m_Textures;
    MusicPlayer  m_music;

	

};
