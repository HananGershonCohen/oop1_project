#include "Windows.h"
#include <iostream>

Windows::Windows(unsigned int width, unsigned int height) :
    m_pixelSize(50), m_height(height * m_pixelSize), m_width(width * m_pixelSize),
    m_window(sf::VideoMode(m_width, m_height), "First Window") { }
