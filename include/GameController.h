#pragma once
#include <SFML/Graphics.hpp>
#include "FirstWindow.h"

class GameController
{
public:
	GameController();
	void run();

private:
	FirstWindow m_firstWindow;

};

