#include "stdafx.h"
#include "GameStats.h"
#include <iostream>
#include <sstream>

GameStats::GameStats()
{
	m_font.loadFromFile("graphics/Arial.ttf");
}

void GameStats::print(sf::RenderWindow & windowRef, Player& PlayerRef)
{
	// Titel
	m_Title.setFont(m_font);
	m_Title.setCharacterSize(16);
	m_Title.setPosition(0, 0);
	m_Title.setFillColor(sf::Color::Black);
	m_Title.setStyle(sf::Text::Bold | sf::Text::Underlined);
	m_Points.setString("Punkte");


	// Player Points
	m_Points.setFont(m_font);
	m_Points.setCharacterSize(14);
	m_Points.setFillColor(sf::Color::Black);
	m_Points.setPosition(0, 25);
	PlayerRef.get_points();
	string = "Punkte: ";
	string = string + Convert(PlayerRef.get_points());
	m_Points.setString(string);

	// Player Lives
	m_Lives.setFont(m_font);
	m_Lives.setCharacterSize(14);
	m_Lives.setFillColor(sf::Color::Black);
	m_Lives.setPosition(0, 50);
	PlayerRef.get_lives();
	string = "Leben: ";
	string = string + Convert(PlayerRef.get_lives());
	m_Lives.setString(string);


	windowRef.draw(m_Title);
	windowRef.draw(m_Points);
	windowRef.draw(m_Lives);
	

}



std::string GameStats::Convert(float number)
{

	std::ostringstream buff;
	buff << number;
	return buff.str();

}

