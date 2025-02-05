#pragma once
#include <SFML/Graphics.hpp>

enum ObjName
{
    E_Exit, // default = 0
    Start,
    Help,
    Font,
    E_Wall,
    E_Robot,
    E_Rock,
    E_Guard,
    E_Door,
    E_Temp,
    E_Bomb,
    E_Fire,
    E_Gift1,
    E_Gift2,
    E_Gift3,
    E_Gift4,
    Tile
};

enum Snd
{
    hurt,
    explosion,
    bombTic
};

namespace Place
{
    sf::Vector2f toPlace(const sf::Vector2f& position, float pixelSize);
  

    namespace Directions 
    {
        const sf::Vector2f Center{ 0.0f,  0.0f }; //
        const sf::Vector2f Right{ 1.0f,  0.0f }; // ימינה
        const sf::Vector2f Left{ -1.0f,  0.0f }; // שמאלה
        const sf::Vector2f Up{ 0.0f, -1.0f }; // למעלה
        const sf::Vector2f Down{ 0.0f,  1.0f }; // למטה
    
    }
}

namespace Score 
{
    const int Guard{ 3 };
    const int NextLevel{ 25 };
}

namespace Data
{
    const unsigned int  pixelSize = 50;
    const unsigned int halfPixelSize = 25;
    const int lifeRobot = 5;
    const int throwable = 5;
}