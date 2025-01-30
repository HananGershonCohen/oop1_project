#pragma once
#include <SFML/Graphics.hpp>
#include "SfmlManager.h"
#include "ObjName.h"

class Information
{
public:
	Information(SfmlManager&);
	void setLevelFinish(const bool);
	bool getLevelFinish() const;
	void draw(sf::RenderWindow&);

private:
	bool m_levelCompleted;
	int m_score;
	SfmlManager& m_SfmlManager;
};