#include "Door.h"

Door::Door(sf::Vector2f location, SfmlManager& sfmlManager)
	:StaticObject(location, sf::Sprite{ sfmlManager.getTexture(ObjName::Door) }, ObjName::Door)
{
}