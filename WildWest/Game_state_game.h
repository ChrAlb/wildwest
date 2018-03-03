#pragma once

#include <SFML\Graphics.hpp>
#include <list>

#include "Game_state.h"
#include "TextureHolder.h"
#include "Player.h"
#include "Enemy.h"



class GameStateGame : public GameState
{
private:

	//******************
	// falls debug= true; Kollisionsboxen werden angezeigt
	bool debug = false;
	//******************

	sf::View gameview;
	sf::View bgview;

    TextureHolder th;
	Sprite m_BackgroundSprite;
	Texture m_BackgroundTexture;
	
	Texture m_Tree;
	Sprite m_Tree_Sprite;

	//Player m_player;
	
	LevelManager m_LM;

	const int TILE_SIZE = 50;
	const int VERTS_IN_QUAD = 4;

	const int GRAVITY = 300;

	bool m_newlevelrequiered = true;
	bool m_Playing = false;

	VertexArray m_VALevel;

	float oldpos;

	int** m_ArrayLevel = NULL;

	Texture m_TextureTiles;

	void loadLevel();

	bool detectCollisions(PlayableCharacter& character);

	bool detectSlope(PlayableCharacter & character);


	sf::RectangleShape  head_box;
	sf::RectangleShape  feet_box;
	sf::RectangleShape  left_box;
	sf::RectangleShape  right_box;
	sf::RectangleShape  box;
	sf::RectangleShape  box_position;

	std::list<PlayableCharacter*> objects;
	std::list<PlayableCharacter*>::iterator iter;
	std::list <PlayableCharacter* >::iterator iter2;

	Player *player;
	Enemy *enemy;


	sf::Font m_font;
	sf::Text text;

	bool m_onSlope = false;
	

public:

	

	virtual void draw(const float dt);
	virtual void update(const float dt);
	virtual void handleInput();

	
	GameStateGame(Game* game);
};
