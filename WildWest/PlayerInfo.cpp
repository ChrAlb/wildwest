#include "stdafx.h"
#include "PlayerInfo.h"

PlayerInfo::PlayerInfo()
{
	m_font.loadFromFile("graphics/Arial.ttf");
}

void PlayerInfo::print(sf::RenderWindow & windowRef, Player& PlayerRef)
{
	m_test.setFont(m_font);
	m_test.setCharacterSize(12);
	m_test.setString("Scheisse");
	m_test.setFillColor(sf::Color::Black);

	PlayerRef.getPosition();
	
	windowRef.draw(m_test);
}

