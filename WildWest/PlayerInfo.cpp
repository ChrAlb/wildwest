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
	// Titel
	m_title.setFont(m_font);
	m_title.setCharacterSize(16);
	m_title.setFillColor(sf::Color::Black);
	m_title.setStyle(sf::Text::Bold | sf::Text::Underlined);
	m_title.setString("Player Information");

	
    // Player Position
	m_pos.setFont(m_font);
	m_pos.setCharacterSize(14);
	m_pos.setFillColor(sf::Color::Black);
	m_pos.setPosition(0, 25);
	PlayerRef.getPosition();
	string = "Top: ";
	string = string + Convert(PlayerRef.getPosition().top);
	string = string + "    Left:  ";
	string = string + Convert(PlayerRef.getPosition().left);
	
	m_pos.setString(string);
	
	windowRef.draw(m_title);
	windowRef.draw(m_pos);
}

std::string PlayerInfo::Convert(float number)
{
	
		std::ostringstream buff;
		buff << number;
		return buff.str();
	
}

