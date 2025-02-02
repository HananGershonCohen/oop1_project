#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "ObjName.h"
#include <iostream>


class SfmlManager
{
public:
	SfmlManager(); // c-tor load file to sf objects.
	sf::Texture& getTexture(ObjName); // return reference of texture according the ObgName(Enum). 
	sf::Text getText(ObjName) const; // return reference of font.
	sf::SoundBuffer& getSound(Snd);

private:
	sf::Texture m_ExitTex;
	sf::Texture m_HelpTex;
	sf::Texture m_StartTex;
	sf::Texture m_RobotTex;
	sf::Texture m_WallTex;
	sf::Texture m_RockTex;
	sf::Texture m_Guard;
	sf::Texture m_DoorTex;
	sf::Texture m_BombTex;
	sf::Texture m_fireTex;
	sf::Texture m_gameOverTex;
	sf::Font m_font;
	sf::SoundBuffer m_hurtSnd;
	sf::SoundBuffer m_explSnd;
	sf::Music m_menuSnd;
};