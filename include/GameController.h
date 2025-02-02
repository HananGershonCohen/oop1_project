#pragma once
#include <string>
#include <memory>
#include <fstream>
#include <vector>
#include "FirstWindow.h"
#include "SfmlManager.h"
#include "StaticObject.h"
#include "GameBoard.h"
#include "MovingObject.h"
#include "Rock.h"
#include "Robot.h"
#include "Guard.h"
#include "Door.h"
#include "Wall.h"
#include "Bomb.h"
#include "Information.h"
#include "CountdownTimer .h"

class GameController
{
public:
	GameController();

	void run();

private:
	sf::Clock m_gameClock;
	sf::Music m_soundGame;
	sf::Vector2f m_robotLoc;
	std::vector <std::unique_ptr<StaticObject>> m_staticObjVec;
	std::vector <std::unique_ptr<MovingObject>> m_movingObjVec;
	std::vector <std::unique_ptr<Bomb>> m_BombVec;
	SfmlManager m_SfmlManager;
	Information m_information;
	int m_numLevel = 2;
	unsigned int m_height = 0;
	unsigned int m_width = 0;

	void handleCollisionController(MovingObject&);
	void readAndAnalyze(const std::string&);
	void updateThisLine(const std::string&);
	void analyzeObj(char&, int);
	void handleFirstWindow(FirstWindow&) const;
	void clearAllVec();
	void gameOver() const;
	void playMusic();
	//-------------------------------------
	void restartObjPlace();
	//void mainLoop(sf::RenderWindow&);
	void draw(sf::RenderWindow&);
	void handleEvent();
	//-------------------------------------
	void addBomb();
	void deleteObjFromVec();
};