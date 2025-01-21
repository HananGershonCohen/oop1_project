#include "Guard.h"

Guard::Guard(sf::Vector2f location, SfmlManager& SfmlMan) :
	MovingObject (location , SfmlMan , ObjName::E_Guard)
{
}

void Guard::updateDirection(sf::Vector2f robotLoc)
{
    auto& guardLoc = m_location;
    sf::Vector2f direction(0, 0);

    // חישוב ההפרש בכל ציר
    float deltaX = robotLoc.x - guardLoc.x;
    float deltaY = robotLoc.y - guardLoc.y;

    // אם ההפרש בציר X גדול יותר, השומר יזוז על ציר ה-X
    if (std::abs(deltaX) > std::abs(deltaY))
    {
        if (robotLoc.x > guardLoc.x)
        {
            direction.x += 1; // Move right
        }
        else if (robotLoc.x < guardLoc.x)
        {
            direction.x -= 1; // Move left
        }
    }
    // אחרת, השומר יזוז על ציר ה-Y
    else
    {
        if (robotLoc.y > guardLoc.y)
        {
            direction.y += 1; // Move down
        }
        else if (robotLoc.y < guardLoc.y)
        {
            direction.y -= 1; // Move up
        }
    }

    //m_direction = direction;
    setDirection(direction);

}

//void Guard::setLocation(sf::Vector2f& diraction)
//{
//    m_location.x += diraction.x;
//    m_location.y += diraction.y;
//}

void Guard::move(float deltaTime)
{
    m_image.move(m_direction.x * (1 * m_pixelSize * deltaTime), m_direction.y * (1 * m_pixelSize * deltaTime));
    m_location.x += m_direction.x * (1 * m_pixelSize * deltaTime);
    m_location.y += m_direction.y * (1 * m_pixelSize * deltaTime);
}
