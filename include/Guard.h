#pragma once
#include <SFML/Graphics.hpp>
#include "ObjName.h"
#include "SfmlManager.h"
#include "MovingObject.h"

class Guard : public MovingObject
{
public:
	Guard(sf::Vector2f&, SfmlManager&);
	sf::Vector2f moveGuard(sf::Vector2f&);

private:

};