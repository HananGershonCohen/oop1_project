#include "Bomb.h"

Bomb::Bomb(sf::Vector2f location, SfmlManager& sfmlManager) :
	StaticObject(location, sf::Sprite(sfmlManager.getTexture(ObjName::E_Bomb)), ObjName::E_Bomb), m_clock() ,
	m_fireSpr(sf::Sprite(sfmlManager.getTexture(ObjName::Fire)))
{
}

void Bomb::draw(sf::RenderWindow& window)
{
	StaticObject::draw(window);
}

void Bomb::updateState()
{
	float elapsedTime = m_clock.getElapsedTime().asSeconds();

	// ����� ������ �� ���� ���� �-4 �����, ���� �� ����� ��� �� ������
	if (elapsedTime > 4 && !m_textureUpdated) {
		m_image.setTexture(*m_fireSpr.getTexture());
		m_textureUpdated = true; // ���� ������� ������
	}

	// ��� �� ����� ���� �� ���� ���� �-6 �����
	if (elapsedTime > 6) {
		m_Dead = true;
	}
}