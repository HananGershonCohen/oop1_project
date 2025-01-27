#pragma once
#include "StaticObject.h"
#include "ObjName.h"
#include "SfmlManager.h"

class Bomb :public StaticObject
{
public: 
	Bomb(sf::Vector2f, SfmlManager&);
	void updateState();
	virtual void draw(sf::RenderWindow& window);


private:
	sf::Clock m_clock;
	sf::Sprite m_fireSpr;
	bool m_textureUpdated = false;
};