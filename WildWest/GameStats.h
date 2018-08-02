#pragma once

#include <SFML\Graphics.hpp>
#include "Player.h"
#include "ResourceHolder.h"
#include "ResourceIdentifiers.h"


class GameStats

{
public:
	GameStats();
	void print(sf::RenderWindow& windowRef, Player& RefPlayer);

	void addpointfordeadeney();

	void subtractlive();
	

private:

	const int m_pointsperdeathenemy = 50;
	int m_lives;
	int m_points;


	FontHolder m_fonts;


	sf::Text m_Title;
	sf::Text m_Points;
	sf::Text m_Lives;
	
	sf::Font m_font;
	String string;

	std::string Convert(float number);


};

