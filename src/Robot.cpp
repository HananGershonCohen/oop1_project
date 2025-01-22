#include "Robot.h"

Robot::Robot(sf::Vector2f location, SfmlManager& sfmlMan)
	: MovingObject(location, sfmlMan, ObjName::E_Robot), m_firstLoc{ location.x * m_pixelSize, location.y * m_pixelSize },m_sfmlManager {sfmlMan}{}

//-----------------------------------------------------------
void Robot::updateDirection(sf::Vector2f)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		setDirection((sf::Vector2f{ 1, 0 }));
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		setDirection((sf::Vector2f{ -1, 0 }));
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		setDirection((sf::Vector2f{ 0, -1 }));
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		setDirection((sf::Vector2f{ 0, 1 }));
	}
	else
		setDirection((sf::Vector2f{ 0, 0 })); // defulte nat moving


}

void Robot::loseLife()
{
	// if life > 0 
	m_life--;
	// else
	// GameOver.
}

void Robot::handleCollision(StaticObject& other)
{
	if (this->collidesWith(other))
	{
		std::cout << "Robot touch at StaticObject \n";
		other.handleCollision(*this); // swap
		// continue to wall->Robot OR guard->Robot
	}
}


void Robot::draw(sf::RenderWindow& window)
{
	StaticObject::draw(window);
	
	sf::Text text = m_sfmlManager.getText(ObjName::Font);

	//2*50 ==> This is the extra space in the window for displaying the data. 
	auto posy = window.getSize().y - (2 * 50); 
	
	text.setPosition(20, posy);
	text.setString(std::to_string(m_life));
	text.setCharacterSize(24);
	const sf::Color lightBlue(173, 216, 230); 
	text.setFillColor(lightBlue);

	window.draw(text); 
	
}

void Robot::move(float deltaTime)
{
	m_image.move(m_direction.x * (2 * m_pixelSize * deltaTime), m_direction.y * (2 * m_pixelSize * deltaTime));
	m_location.x += m_direction.x * (2 * m_pixelSize * deltaTime);
	m_location.y += m_direction.y * (2 * m_pixelSize * deltaTime);
}
