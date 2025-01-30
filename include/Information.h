#pragma once
#include <SFML/Graphics.hpp>
#include "SfmlManager.h"
#include "ObjName.h"

class Information
{
public:
	Information(SfmlManager&);
	void setLevelFinish(const bool);
	void setScore(const int);
	void loseRobotLife();
	void increaseGuardCount();

	int getGuardCount() const;
	int getRobotLife() const;
	bool getLevelFinish() const;

	void draw(sf::RenderWindow&);

private:
	bool m_levelCompleted;
	int m_score;
	int m_lifeRobot = 5;
	int m_countGuard;
	SfmlManager& m_SfmlManager;
};