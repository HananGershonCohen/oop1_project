#pragma once
#include "MovingObject.h"
#include "StaticObject.h"
#include "ObjName.h"
#include "SfmlManager.h"

class Robot :public MovingObject
{
public:
	Robot(sf::Vector2f, SfmlManager&);
	void goToFirstLoc() { m_location = m_firstLoc; }
	sf::Vector2f getLocation() const { return m_location; }
	void updateDirection();

	virtual void handleCollision(StaticObject& other) override
	{
		std::cout << "class Robot : handleCollision other \n";

		if (this->touch(other.getLocation()))
		{
			std::cout << "class Robot : this->touch(other.getLocation()--> TRUE \n";

			other.handleCollision(*this);
		}
		else 
		{
			std::cout << "class Robot : this->touch(other.getLocation()--> False \n";
		}
	}

	virtual void draw(sf::RenderWindow&) override ;
	virtual void move (float) override;

private:
	sf::Vector2f m_firstLoc;
	int m_life = 5;
	float m_time = 10;// for new is default
	SfmlManager m_sfmlManager{};

};