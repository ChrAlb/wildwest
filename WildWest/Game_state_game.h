#pragma once

#include <SFML\Graphics.hpp>
#include <list>

#include "Game_state.h"
#include "ResourceHolder.h"
#include "ResourceIdentifiers.h"
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

	Sprite m_BackgroundSprite;
	Sprite m_Tree_Sprite;

	TextureHolder m_Textures;

	leveldate m_leveldaten;

	
	LevelManager m_LM;

	const int TILE_SIZE = 50;
	const int VERTS_IN_QUAD = 4;

	const int GRAVITY = 300;

	bool m_newlevelrequiered = true;
	bool m_Playing = false;

	
	VertexArray m_VALevel;

	float oldpos;

	int** m_ArrayLevel = NULL;

	void loadLevel();

	bool detectCollisions(PlayableCharacter& character);

	bool checkNextTile(Vector2f &vel, Vector2i &tile_pos, int &slopenumber);

	int slopenumber;
	

	sf::RectangleShape  head_box;
	sf::RectangleShape  feet_box;
	sf::RectangleShape  left_box;
	sf::RectangleShape  right_box;
	sf::RectangleShape  center_box;
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
	
	float m_Gravity;

public:

	

	virtual void draw(const float dt);
	virtual void update(const float dt);
	virtual void handleInput();
	 
	
	GameStateGame(Game* game);
};
