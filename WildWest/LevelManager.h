#pragma once

#include <SFML/Graphics.hpp>

using namespace sf;
using namespace std;

struct leveldate
{
	string BGFileName;
	string TilSetName;
	string LevelName;

};


class LevelManager
{
private:
	Vector2i m_LevelSize;
	Vector2f m_StartPosition;
	float m_TimeModifier = 1;
	int VArraySize;
	int m_CurrentLevel = 0;
	const int NUM_LEVELS = 2;
	bool m_allLevel = false;
	
	leveldate m_leveldata;
	

public:

	const int TILE_SIZE = 50;
	const int VERTS_IN_QUAD = 4;
	
	float getTimeLimit();
    Vector2f getStartPosition();
	int** nextLevel(VertexArray& rVaLevel);
	Vector2i getLevelSize();
	int getCurrentLevel();
	bool get_allLeveldone();
	void set_allLeveldone(bool allLeveldone);
	
};


