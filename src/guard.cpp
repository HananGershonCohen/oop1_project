#include "Guard.h"

Guard::Guard(sf::Vector2f& location, SfmlManager& SfmlMan) :
	MovingObject (location , SfmlMan , ObjName::E_Guard)
{
}

sf::Vector2f Guard::moveGuard(sf::Vector2f& robotLoc)
{
    auto& guardLoc = m_location; // I changed the name to make the code more readable.
    sf::Vector2f direction(0, 0);

    // Checking the distance. 

    // X-axis
    if (robotLoc.x > guardLoc.x)
    {
        direction.x += 1; // Right
    }
    else if (robotLoc.x < guardLoc.x)
    {
        direction.x -= 1;  // Left

    }

    // Y - axis
    if (robotLoc.y > guardLoc.y)
    {
        direction.y += 1;  // Down
    }
    else if (robotLoc.y < guardLoc.y)
    {
        direction.y -= 1;  // Up
    }

    m_direction = direction;
    return m_direction;
}
