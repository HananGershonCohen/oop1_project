#pragma once 
#include <SFML/Graphics.hpp>
#include <iostream>
#include "ObjName.h"

class ButtonStart
{
public:
	ButtonStart();
	

private:
	sf::RectangleShape m_button;
	sf::Vector2f m_location;
};

