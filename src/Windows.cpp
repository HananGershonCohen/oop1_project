#include "Windows.h"
#include <iostream>

Windows::Windows(unsigned int width, unsigned int height)
{
    m_width = width * m_pixelSize; 
    m_height = height * m_pixelSize;
    m_window.create(sf::VideoMode(m_width, m_height), "First Window"); 
}
