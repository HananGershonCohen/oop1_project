#include "Bomb.h"

Bomb::Bomb(sf::Vector2f location, SfmlManager& sfmlManager) :
	StaticObject(location, sf::Sprite(sfmlManager.getTexture(ObjName::E_Bomb)), ObjName::E_Bomb), m_clock() ,
	m_fireSpr(sf::Sprite(sfmlManager.getTexture(ObjName::Fire))){}

void Bomb::updateState()
{
	float elapsedTime = m_clock.getElapsedTime().asSeconds();

	// החלפת התמונה אם עברו יותר מ-4 שניות, והאם לא עדכנו כבר את התמונה
	if (elapsedTime > 4 && !m_exploded) {
		m_image.setTexture(*m_fireSpr.getTexture());
		m_exploded = true; // סימן שהתמונה הוחלפה
	}

	// סמן את הפצצה כמתה אם עברו יותר מ-6 שניות
	if (elapsedTime > 6) {
		m_Dead = true;
	}
}

bool Bomb::IsExploded()
{
	return m_exploded;
}

void Bomb::handleCollision(Guard& guard)
{
	if (m_exploded){
		guard.setDead(true);
	}
}

void Bomb::handleCollision(Robot& robot)
{
	if (m_exploded){
		robot.loseLife();
		// need to: go to next level. 
		robot.setDead(true);
	}
}

