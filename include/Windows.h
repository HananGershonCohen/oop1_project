#pragma once
#include <SFML/Graphics.hpp>

class Windows
{
public:
	Windows(unsigned int, unsigned int);

protected:
	const unsigned int m_pixelSize;
	unsigned int m_height;
	unsigned int m_width;
	sf::RenderWindow m_window;
};


