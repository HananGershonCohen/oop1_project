#pragma once
#include "FirstWindow.h"
#include <SfmlManager.h>
#include "StaticObject.h"
#include "GameBoard.h"
#include "MovingObject.h"
#include "Robot.h"
#include "Guard.h"
 
class GameController
{
public:
	GameController() = default;
	void run();

private:
	SfmlManager m_SfmlManager{};
	void handleFirstWindow(FirstWindow&) const;
	sf::Vector2f getDirection();
	
};

