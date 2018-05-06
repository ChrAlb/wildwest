#pragma once
#include <SFML\Graphics.hpp>
#include "Player.h"

class PlayerInfo

{
public:
	PlayerInfo();
	void print(sf::RenderWindow& windowRef, Player& RefPlayer);
	

private:

	sf::Text m_title;
	sf::Text m_pos;

	sf::Font m_font;
	String string;
	
	std::string Convert(float number);


};
