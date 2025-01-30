#include "Information.h"

Information::Information(SfmlManager& sfMan) : m_SfmlManager(sfMan), m_levelCompleted(false),m_score(0), m_countGuard(0){}

void Information::setLevelFinish(const bool flag)
{
	m_levelCompleted = flag;

	if (flag)
		m_score += (3 * m_countGuard) + 25;
}

void Information::setScore(const int score)
{
	m_score += score;
}

void Information::loseRobotLife()
{
	m_lifeRobot--;
}

void Information::increaseGuardCount() {
	m_countGuard++;
}

int Information::getGuardCount() const {
	return m_countGuard;
}

int Information::getRobotLife() const
{
	return m_lifeRobot;
}

bool Information::getLevelFinish() const
{
	return m_levelCompleted;
}

void Information::draw(sf::RenderWindow& window)
{
	auto Life = m_SfmlManager.getText(ObjName::Font);
	auto score = m_SfmlManager.getText(ObjName::Font);
	const sf::Color lightBlue(173, 216, 230);
	//2*50 ==> This is the extra space in the window for displaying the data. 
	//------life---------
	auto posy = window.getSize().y - (2 * 50);
	Life.setPosition(0, posy);
	score.setPosition(70, posy);

	Life.setString("Life: \n " + std::to_string(m_lifeRobot));
	score.setString("Score: \n " + std::to_string(m_score));

	Life.setCharacterSize(24);
	score.setCharacterSize(24);
	Life.setFillColor(lightBlue);
	score.setFillColor(lightBlue);

	window.draw(Life);
	window.draw(score);



	//------time---------
	//text.setPosition(70, posy);
	//text.setString("The Time is: \n     " + std::to_string(m_seconds / 60) + ":" + std::to_string(m_seconds % 60));
	//text.setCharacterSize(24);
	//text.setFillColor(sf::Color::Red);
	//window.draw(text);
}
