#pragma once
#include <SFML/Graphics.hpp>
#include "SfmlManager.h"
#include "ObjName.h"

class Robot;

class StaticObject
{
public:
	StaticObject(sf::Vector2f, sf::Sprite, ObjName);
	
	ObjName getType() const { return m_type; }
	bool touch(sf::Vector2f location) const; 
	sf::Vector2f getLocation() const;
	virtual void draw(sf::RenderWindow&);

	virtual void handleCollision(StaticObject&) {
		std::cout << "class StaticObject: handleCollision(StaticObject&)... \n";
	}
	virtual void handleCollision(Robot&) {
		std::cout << "class StaticObject: handleCollision(Robot&)... \n";
	}

	virtual ~StaticObject() = default;

protected:
	const int m_pixelSize;
	sf::Sprite m_image;
	sf::Vector2f getLoc() const { return m_location; }
	sf::Vector2f m_location;
	sf::Vector2f calculateLocation(sf::Vector2f);
	
private:
	//--- data_member ---



	ObjName m_type;

	//---- function --------
	void setSpritLoc();


};