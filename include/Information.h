#pragma once
#include <SFML/Graphics.hpp>

class Information
{
public:
	Information();
	void setLevelFinish(const bool);
	bool getLevelFinish() const;

private:
	bool m_levelCompleted;
	int m_score;
};