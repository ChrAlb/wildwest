#include "stdafx.h"
#include "GameStats.h"
#include <iostream>
#include <sstream>

GameStats::GameStats()
{
	m_fonts.load(Fonts::ComicS, "graphics/Comics.ttf");
	
	m_lives = 3;
	m_points = 0;
}
 
void GameStats::print(sf::RenderWindow & windowRef, Player& PlayerRef)
{
	// Titel
	m_Title.setFont(m_fonts.get(Fonts::ComicS));
	m_Title.setCharacterSize(16);
	m_Title.setPosition(0, 0);
	m_Title.setFillColor(sf::Color::Black);
	m_Title.setStyle(sf::Text::Bold | sf::Text::Underlined);
	m_Title.setString("Spielstand:");


	// Player Points
	m_Points.setFont(m_fonts.get(Fonts::ComicS));
	m_Points.setCharacterSize(14);
	m_Points.setFillColor(sf::Color::Black);
	m_Points.setPosition(0, 25);
	
	string = "Punkte:     ";
	string = string + Convert(m_points);
	m_Points.setString(string);

	// Player Lives
	m_Lives.setFont(m_fonts.get(Fonts::ComicS));
	m_Lives.setCharacterSize(14);
	m_Lives.setFillColor(sf::Color::Black);
	m_Lives.setPosition(0, 50);
	
	string = "Leben:     ";
	string = string + Convert(m_lives);
	m_Lives.setString(string);


	windowRef.draw(m_Title);
	windowRef.draw(m_Points);
	windowRef.draw(m_Lives);
	

}

void GameStats::addpointfordeadeney()
{
	m_points = m_points + m_pointsperdeathenemy;
}

void GameStats::subtractlive()
{
	m_lives = m_lives - 1;
}



std::string GameStats::Convert(float number)
{

	std::ostringstream buff;
	buff << number;
	return buff.str();

}

