#pragma once 
#include <SFML/Graphics.hpp>
#include <iostream>
#include "ObjName.h"
#include "SfmlManager.h"

class Button
{
public:
	//Button(sf::Vector2f, sf::Sprite&, ObjName);
	bool userPressOnTheButton(sf::Vector2f&) const;
	void draw(sf::RenderWindow& window) const;
	
	ObjName getObjType() const { return m_objType; }
	
	Button(sf::RectangleShape, ObjName, SfmlManager&);
	std::string textButton(ObjName);

private:
	sf::Vector2f VertexUp;
	sf::Sprite m_image;
	ObjName m_objType;
	const int m_pixelSize = 50;




	sf::RectangleShape m_button;
	SfmlManager& m_sfmlManger;
	sf::Text m_text;
};
