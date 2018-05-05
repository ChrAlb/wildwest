#pragma once
#include <SFML\Graphics.hpp>
#include "Player.h"

class PlayerInfo

{
public:
	PlayerInfo();
	void print(sf::RenderWindow& windowRef);
	void setTest(float test);

private:

	sf::Text m_test;
	sf::Font m_font;
	float q_test;


};
