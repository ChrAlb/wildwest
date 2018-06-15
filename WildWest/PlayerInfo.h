#pragma once
#include <SFML\Graphics.hpp>
#include "Player.h"
#include "Enemy.h"

class PlayerInfo

{
public:
	PlayerInfo();
	void print(sf::RenderWindow& windowRef, Player& RefPlayer);
	void printEnemy(sf::RenderWindow& windowRef, Enemy& RefPlayer);

private:

	sf::Text m_title;
	sf::Text m_pos;
	sf::Text m_jumpFrames;
	sf::Text m_onslope;
	sf::Text m_slopeend;

	sf::Font m_font;
	String string;
	
	std::string Convert(float number);


};
