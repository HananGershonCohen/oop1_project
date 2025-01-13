#pragma once
#include <SFML/Graphics.hpp>

class Windows
{
public:
	Windows(unsigned int, unsigned int);
	unsigned int m_height;
	unsigned int m_width;
	const unsigned int m_pixelSize = 50;
	sf::RenderWindow m_window;
};


