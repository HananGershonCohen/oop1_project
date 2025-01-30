#include "Guard.h"

Guard::Guard(sf::Vector2f location, SfmlManager& SfmlMan, Information& info) :
    MovingObject(location, SfmlMan, ObjName::E_Guard , info), m_firstLoc{ location.x * m_pixelSize, location.y * m_pixelSize } {}

//--------------------------------------------------------------
void Guard::dountMove()
{
    int newX = (m_location.x + 25) / 50;
    int newY = (m_location.y + 25) / 50;
    newX *= 50;
    newY *= 50;
    m_location = sf::Vector2f{ (float)newX, (float)newY };
}
//--------------------------------------------------------------
void Guard::updateDirection(sf::Vector2f robotLoc)
{
    m_need2restartPlace = false;
    sf::Vector2f direction = { 0, 0 };

    //
    int newX = (robotLoc.x + 25) / m_pixelSize;
    int newY = (robotLoc.y + 25) / m_pixelSize;
    newX *= m_pixelSize;
    newY *= m_pixelSize;
    robotLoc = sf::Vector2f{ (float)newX, (float)newY };
    //

    if (std::abs(robotLoc.x - m_location.x) > (m_pixelSize / 10)) // because its almost never will ba 0 i took exception of 10 parcent
    {
        // Move horizontally
        direction.x = (robotLoc.x > m_location.x) ? 1.f : -1.f;
    }
    else /*if (std::abs(robotLoc.y - m_location.y) > 0)*/ {
        // Move vertically
        direction.y = (robotLoc.y > m_location.y) ? 1.f : -1.f;
    }

    setDirection(direction);
}
//--------------------------------------------------------------
void Guard::move(float deltaTime)
{
    m_image.move(m_direction.x * (m_pixelSize * deltaTime), m_direction.y * (m_pixelSize * deltaTime));
    m_location.x += m_direction.x * (m_pixelSize * deltaTime);
    m_location.y += m_direction.y * (m_pixelSize * deltaTime);
}

void Guard::setDead(bool)
{
    m_information.setScore(5);
    StaticObject::setDead();
}

//--------------------------------------------------------------
void Guard::handleCollision(StaticObject& other)
{
    /* if (this->collidesWith(other))
     {*/
     // std::cout << "Guard touch at StaticObgect \n";
    other.handleCollision(*this); // swap.
    // continue staticObject meet with Guard.
/* }*/
}
//--------------------------------------------------------------
void Guard::handleCollision(Robot& robot)
{
    if (this->collidesWith(robot))
    {
        std::cout << "guard hit a robot. and life-- \n";
        robot.loseLife();
        m_need2restartPlace = true;
    }
}