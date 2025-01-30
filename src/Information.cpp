#include "Information.h"

Information::Information(SfmlManager& sfMan) : m_SfmlManager(sfMan), m_levelCompleted(false),m_score(0) {}

void Information::setLevelFinish(const bool flag)
{
	m_levelCompleted = flag;
}

bool Information::getLevelFinish() const
{
	return m_levelCompleted;
}

void Information::draw(sf::RenderWindow& window)
{
//	auto text = m_sfmlManager.getText(ObjName::Font);

//	//2*50 ==> This is the extra space in the window for displaying the data. 
//	//------life---------
//	auto posy = window.getSize().y - (2 * 50);
//	text.setPosition(0, posy);
////	text.setString("Life: \n " + std::to_string(m_life));
//	text.setCharacterSize(24);
//	const sf::Color lightBlue(173, 216, 230);
//	text.setFillColor(lightBlue);
//	window.draw(text);
//
//	//------time---------
//	text.setPosition(70, posy);
////	text.setString("The Time is: \n     " + std::to_string(m_seconds / 60) + ":" + std::to_string(m_seconds % 60));
//	text.setCharacterSize(24);
//	text.setFillColor(sf::Color::Red);
//	window.draw(text);
}
