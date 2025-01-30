#pragma once
#include <SFML/Graphics.hpp>
#include "SfmlManager.h"
#include "ObjName.h"
#include "CountdownTimer .h"

class Information
{
public:
	Information(SfmlManager&);
	void setLevelFinish(const bool);
	void setScore(const int);
	void loseRobotLife();
	void increaseGuardCount();
	void setLevel(const int);
	void setRobotKill(const bool);

	bool getRobotKill() const;
	int getLevel() const;
	int getGuardCount() const;
	int getRobotLife() const;
	bool getLevelFinish() const;
	CountdownTimer& getClock();

	void draw(sf::RenderWindow&);

private:
	bool m_levelCompleted;
	bool m_robotKill;
	int m_score;
	int m_lifeRobot = 5;  // default
	int m_countGuard;
	int m_level;
	SfmlManager& m_SfmlManager;
	CountdownTimer m_clock{ 0 };
};