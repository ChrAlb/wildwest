#include "stdafx.h"
#include "PlayerInfo.h"
#include <iostream>
#include <sstream>

PlayerInfo::PlayerInfo()
{
	m_font.loadFromFile("graphics/Arial.ttf");
}

void PlayerInfo::print(sf::RenderWindow & windowRef, Player& PlayerRef)
{
	m_txt.setFont(m_font);
	m_txt.setCharacterSize(12);
	
	m_txt.setFillColor(sf::Color::Black);

	PlayerRef.getPosition();

    m_txt.setString(Convert(PlayerRef.getPosition().top));

	

	
	
	windowRef.draw(m_txt);
}

std::string PlayerInfo::Convert(float number)
{
	
		std::ostringstream buff;
		buff << number;
		return buff.str();
	
}

