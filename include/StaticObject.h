#pragma once
#include <SFML/Graphics.hpp>
#include "SfmlManager.h"
#include "ObjName.h"

class Robot;
class Guard;
class Bomb;
class Rock;

class StaticObject
{
public:
	StaticObject(sf::Vector2f, sf::Sprite, ObjName);
	virtual ~StaticObject() = default;

	ObjName getType() const { return m_type; }
	bool touch(sf::Vector2f location) const;
	sf::Vector2f getLocation() const;
	bool collidesWith(const StaticObject&) const;
	bool checkCollision(StaticObject&) const;
	virtual void setDead(bool = true);
	bool IsDead() const;
	//--- VIRTUAL ---
	virtual void draw(sf::RenderWindow&);

	// --- Double Dispatch ---
	virtual void handleCollision(StaticObject&) {};
	virtual void handleCollision(Robot&) {};
	virtual void handleCollision(Guard&) {};
	virtual void handleCollision(Rock&) {};


protected:
	void setLocation() { m_image.setPosition(m_location); }

	const int m_pixelSize;
	sf::Sprite m_image;
	sf::Vector2f getLoc() const { return m_location; }
	sf::Vector2f m_location;
	bool m_Dead = false;
	sf::Vector2f calculateLocation(sf::Vector2f);

private:
	//--- data_member ---

	ObjName m_type;
	//---- function --------
	void setSpritLoc();


};