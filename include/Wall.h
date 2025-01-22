#pragma once
#include "StaticObject.h"
#include "ObjName.h"
#include "SfmlManager.h"

class Wall :public StaticObject
{
public:
	Wall(sf::Vector2f, SfmlManager&);

	// --- Double Dispatch ---
	virtual void  handleCollision(Robot&) override;
	virtual void  handleCollision(Guard&) override;
	
private:

};