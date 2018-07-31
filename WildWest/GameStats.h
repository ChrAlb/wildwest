#pragma once

#include <SFML\Graphics.hpp>
#include "Player.h"


class GameStats

{
public:
	GameStats();
	void print(sf::RenderWindow& windowRef, Player& RefPlayer);
	

private:

	sf::Text m_Title;
	sf::Text m_Points;
	sf::Text m_Lives;
	
	sf::Font m_font;
	String string;

	std::string Convert(float number);


};

