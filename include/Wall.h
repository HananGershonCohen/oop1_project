#pragma once
#include "StaticObject.h"
#include "ObjName.h"
#include "SfmlManager.h"

class Wall :public StaticObject
{
public:
	Wall(sf::Vector2f, SfmlManager&);
	virtual void  handleCollision(Robot&) override
	{
		std::cout << "class Wall : handleCollision return \n";

	}
private:

};