#pragma once
#include "StaticObject.h"
#include "ObjName.h"
#include "SfmlManager.h"
#include "Information.h"

class MovingObject :public StaticObject
{
public:
	MovingObject(sf::Vector2f, SfmlManager&, ObjName, Information&);
	void setDirection(sf::Vector2f);
	virtual void move(float) {};
	virtual void updateDirection(sf::Vector2f) {};
	virtual ~MovingObject() = default;
	virtual bool need2restartPlace() const { return m_need2restartPlace; }
	virtual void goToFirstLoc() {};
protected:
	sf::Vector2f m_direction{ 0, 0 };// defult nat moving
	Information& m_information;
	bool m_need2restartPlace = false;
};