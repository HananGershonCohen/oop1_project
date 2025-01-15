#pragma once
#include <SFML/Graphics.hpp>
#include "ObjName.h"

class SfmlMananger
{
public:
	SfmlMananger(); // c-tor load file to sf objects.
	sf::Texture& getTexture(ObjName); // return refernce of texture according the ObgName(Enum). 
	sf::Text getText(ObjName) const; // return refernce of font.

private:
	sf::Texture m_ExitTex;
	sf::Texture m_HelpTex;
	sf::Texture m_StartTex;
	sf::Font m_font;
};