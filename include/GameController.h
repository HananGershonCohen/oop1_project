#pragma once
#include "FirstWindow.h"
#include <SfmlManager.h>
#include "GameBoard.h"
 
class GameController
{
public:
	void run();

private:
	SfmlManager m_textureManager{};
	void handleFirstWindow(FirstWindow&) const;

};

