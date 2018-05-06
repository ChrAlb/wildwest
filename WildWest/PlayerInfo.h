#pragma once
#include <SFML\Graphics.hpp>
#include "Player.h"

class PlayerInfo

{
public:
	PlayerInfo();
	void print(sf::RenderWindow& windowRef, Player& RefPlayer);
	

private:

	sf::Text m_txt;
	sf::Font m_font;
	
	std::string Convert(float number);


};
