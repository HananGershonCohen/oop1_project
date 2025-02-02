#include "Robot.h"

Robot::Robot(sf::Vector2f location, SfmlManager& sfmlMan , Information& info)
	: MovingObject(location, sfmlMan, ObjName::E_Robot ,info ), m_firstLoc{ location.x * m_pixelSize, location.y * m_pixelSize }
	, m_sfmlManager{ sfmlMan }
{ }
//-----------------------------------------------------------
void Robot::updateDirection(sf::Vector2f)
{
	m_stopped = m_need2restartPlace = false;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		setDirection(sf::Vector2f{ 1, 0 });
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		setDirection(sf::Vector2f{ -1, 0 });

	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		setDirection(sf::Vector2f{ 0, -1 });
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		setDirection(sf::Vector2f{ 0, 1 });
	}
	else
	{
		setDirection(sf::Vector2f{ 0, 0 }); // default nat moving
		m_stopped = true;
	}

}
//---------------------------------------------------------
void Robot::loseLife()
{
	m_information.loseRobotLife();
	if (m_information.getRobotLife() <= 0)
		m_information.setRobotKill(true);
}
//---------------------------------------------------------
void Robot::dountMove()
{
	int newX = (m_location.x + 25) / 50;
	int newY = (m_location.y + 25) / 50;
	newX *= 50;
	newY *= 50;
	m_location = sf::Vector2f{ (float)newX, (float)newY };
	//-----------------------------
	m_currentFrame = 1;

}

void Robot::FinishLevel(const bool flag) 
{
	m_information.setLevelFinish(flag);
	std::cout << "Robot hit a Door go to next level\n";
}

void Robot::playMusic()
{
	m_hurtSnd.setBuffer(m_sfmlManager.getSound(Snd::hurt));
	m_hurtSnd.setVolume(100);
	m_hurtSnd.play();
}

//---------------------------------------------------------
void Robot::draw(sf::RenderWindow& window)
{
	StaticObject::draw(window);
	drawInformation(window);
}
//---------------------------------------------------------
void Robot::move(float deltaTime)
{
	//---------- update time past -----
	if ((m_time += deltaTime) >= m_seconds + 1)
	{
		m_seconds++;
	}
	//-----------------------------------

	if (m_stopped) // if the robot didnt move dont move
		return;

	m_image.move(m_direction.x * (2 * m_pixelSize * deltaTime), m_direction.y * (2 * m_pixelSize * deltaTime));
	m_location.x += m_direction.x * (2 * m_pixelSize * deltaTime);
	m_location.y += m_direction.y * (2 * m_pixelSize * deltaTime);

}
//---------------------------------------------------------
void Robot::handleCollision(StaticObject& other)
{
	/*if (this->collidesWith(other))
	{*/
	//	std::cout << "Robot touch at StaticObject \n";
	other.handleCollision(*this); // swap
	// continue to wall->Robot OR guard->Robot
/*}*/
}
//---------------------------------------------------------
void Robot::drawInformation(sf::RenderWindow& window)
{
	
}