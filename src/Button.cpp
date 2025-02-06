#include "Button.h"

//-------------------------------------------------------------------
bool Button::userPressOnTheButton(sf::Vector2f& location) const
{
	return m_button.getGlobalBounds().contains(location);
}

void Button::draw(sf::RenderWindow& window) const
{
	window.draw(m_button);
	window.draw(m_text);
} //maybe it should nat be const

Button::Button(sf::RectangleShape rect, ObjName type ,SfmlManager& sfmlMan ) :
	m_objType(type), m_button(rect) , m_sfmlManger(sfmlMan)
{
	m_text = m_sfmlManger.getText(ObjName::Font);
	m_text.setString(textButton(type));
	float buttonWidth = m_button.getSize().x;
	float buttonHeight = m_button.getSize().y;
	float textWidth = m_text.getLocalBounds().width;
	float textHeight = m_text.getLocalBounds().height;
	
	// מיקום הטקסט באמצע הכפתור
	m_text.setPosition(
		m_button.getPosition().x + (buttonWidth - textWidth) / 2,  // מרכז לפי רוחב
		m_button.getPosition().y + (buttonHeight - textHeight) / 2 // מרכז לפי גובה
	);

	m_text.setFillColor(sf::Color::White); // צבע טקסט לבן
	m_text.setCharacterSize(35);
}

std::string Button::textButton(ObjName obj)
{
	switch (obj)
	{
	case E_Exit:
		return "EXIT";
	case Help:
		return "SHOEW HELP";
	case Start:
		return "STERT GAME";
	}
}

//-------------------------------------------------------------------