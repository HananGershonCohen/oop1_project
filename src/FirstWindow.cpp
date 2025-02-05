#include "FirstWindow.h"
#include <fstream>
#include <string>
#include <sstream>
#include <thread>
#include <chrono>

FirstWindow::FirstWindow(SfmlManager& sfmlMan)
	: Windows(15, 15), m_sfmlManager{ sfmlMan }
{
	// חישוב המידות של הכפתורים
	float buttonWidth = m_width / 1.5;   // רוחב הכפתור יהיה חצי מרוחב החלון
	float buttonHeight = m_height / 4; // גובה הכפתור יהיה שליש מגובה החלון

	// חישוב המיקום של הכפתורים
	float spacing = 20.f; // רווח בין הכפתורים

	// חישוב מיקום X כדי למקם את הכפתורים במרכז
	float x = (m_width - buttonWidth) / 2; // למרכז את הכפתור בהיבט האופקי

	// חישוב מיקום Y כדי למקם את הכפתורים אחד מתחת לשני
	float y = (m_height - 3 * buttonHeight - 2 * spacing) / 2; // למרכז את הכפתורים בהיבט האנכי

	// יצירת 3 כפתורים
	sf::RectangleShape button1(sf::Vector2f(buttonWidth, buttonHeight));
	sf::RectangleShape button2(sf::Vector2f(buttonWidth, buttonHeight));
	sf::RectangleShape button3(sf::Vector2f(buttonWidth, buttonHeight));

	// הגדרת צבעים לכפתורים
	button1.setFillColor(sf::Color(0, 122, 255));  // כחול בהיר למתחילים
	button2.setFillColor(sf::Color(34, 139, 34));  // ירוק כהה לעזרה
	button3.setFillColor(sf::Color(220, 20, 60));  // אדום כהה ליציאה

	// הצבת המיקומים של הכפתורים
	button1.setPosition(x, y);
	button2.setPosition(x, y + buttonHeight + spacing); // כפתור 2 נמצא מתחת לכפתור 1
	button3.setPosition(x, y + 2 * (buttonHeight + spacing)); // כפתור 3 נמצא מתחת לכפתור 2

	// הוספת הכפתורים לרשימה
	m_buttons.push_back(Button(button1, ObjName::Start, sfmlMan));
	m_buttons.push_back(Button(button2, ObjName::Help, sfmlMan));
	m_buttons.push_back(Button(button3, ObjName::E_Exit, sfmlMan));

}

//-------------------------------------------------------------------
void FirstWindow::draw()
{
	for (auto& button : m_buttons)
	{
		button.draw(m_window);
	}
}
//-------------------------------------------------------------------
void FirstWindow::customerChoice()
{
	m_need2exit = false; // analyze aviary time
	m_need2exit = false; // analyze aviary time
	sf::Text text;

	playMusic();
	while (m_window.isOpen())
	{
		sf::Event event;
		if (m_window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				m_window.close();
				m_menuSnd.stop();
			}


			if (event.type == sf::Event::MouseButtonPressed)
			{
				sf::Vector2f location = { float(event.mouseButton.x), float(event.mouseButton.y) };
				for (int i = 0; i < m_buttons.size(); i++)
				{
					if (m_buttons[i].userPressOnTheButton(location))
					{
						switch (m_buttons[i].getObjType())
						{
						case ObjName::Start:
							std::cout << "Start button pressed \n";
							m_need2start = true;
							m_window.close();
							m_menuSnd.stop();
							return;
						case ObjName::Help:
							std::cout << "Help button pressed \n";
							text = readHelpFromFile();
							showHelp(text);
							break;
						case ObjName::E_Exit:
							std::cout << "Exit button pressed \n";
							m_need2exit = true;
							m_window.close();
							return;
						}
					}

				}
			}
		}
		m_window.clear();
		draw();
		m_window.display();

	}
}
void FirstWindow::playMusic()
{
	m_menuSnd.openFromFile("menu.wav");
	m_menuSnd.setLoop(true);
	m_menuSnd.play();
}
//------------------------------------------------------------------
sf::Text FirstWindow::readHelpFromFile() const
{
	//I want to read the contents of the file and print it to the SFML window,
	//	(Continue - if there are many characters I want the window to be scrollable.)
	
	std::cout << "reading from file ... \n";

	std::ifstream file("help.txt");
	if (!file)
	{
	std::cerr << "Failed to load help.txt\n";
	}

	std::ostringstream ss; // object to hold the content of the file
	ss << file.rdbuf(); // read the file
	std::string fileContent = ss.str(); // Convert file contents to a string 

	sf::Text text = m_sfmlManager.getText(ObjName::Font); // Returns a text object with a font defined inside it.
	text.setString(fileContent); 
	text.setCharacterSize(24);
	const sf::Color gold(255, 215, 0); // color golg
	const sf::Color silver(192, 192, 192); // color silver
	text.setFillColor(gold);
	text.setOutlineColor(silver);
	text.setOutlineThickness(0.5); 
	text.setPosition(2, 2);


	return text;
}

//void FirstWindow::showHelp(sf::Text& text)
//{
//	// show the ALL text on the window 
//	wrapText(text, m_window.getSize().x - 20); // 20 is some padding from the edges
//
//	
//
//	// create new button.
//	sf::Sprite ExitSprite(m_sfmlManager.getTexture(ObjName::E_Exit));
////	Button button(sf::Vector2f(10, 10), ExitSprite, ObjName::E_Exit);
//
//	//sf::RectangleShape button
//
//	while (m_window.isOpen())
//	{
//		sf::Event event;
//		if (m_window.pollEvent(event))
//		{
//			if (event.type == sf::Event::Closed)
//				return;
//
//			if (event.type == sf::Event::MouseButtonPressed)
//			{
//				sf::Vector2f location = { float(event.mouseButton.x), float(event.mouseButton.y) };
//				//if (button.userPressOnTheButton(location))
//					return;
//			}
//		}
//
//		m_window.clear();
//		m_window.draw(text);
//	//	button.draw(m_window);
//		m_window.display();
//	}
//}

void FirstWindow::showHelp(sf::Text& text)
{
	// הצגת כל הטקסט על החלון
	wrapText(text, m_window.getSize().x - 20); // 20 זה רווח מהקצוות

	// יצירת כפתור יציאה
	sf::RectangleShape exitButton(sf::Vector2f(150.f,100.f)); // גודל הכפתור 250x200
	exitButton.setFillColor(sf::Color::Green);  // צבע אדום כהה (לפי העדפה שלך)

	// חישוב מיקום הכפתור
	float buttonX = m_window.getSize().x * 4 / 5;  // 4/5 מהרחב, בחלק האחרון של הציר X
	float buttonY = m_window.getSize().y * 3 / 4;  // 3/4 מהגובה, בחלק האחרון של הציר Y
	exitButton.setPosition(buttonX, buttonY);  // מיקום הכפתור

	// יצירת אובייקט כפתור
	Button button(exitButton, ObjName::E_Exit, m_sfmlManager);

	while (m_window.isOpen())
	{
		sf::Event event;
		if (m_window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				return;

			if (event.type == sf::Event::MouseButtonPressed)
			{
				sf::Vector2f location = { float(event.mouseButton.x), float(event.mouseButton.y) };
				if (button.userPressOnTheButton(location))  // אם לחצו על הכפתור
					return; // סיים את הפעולה (כפתור נלחץ)
			}
		}

		m_window.clear();
		m_window.draw(text);   // מציירים את הטקסט
		button.draw(m_window); // מציירים את הכפתור
		m_window.display();
	}
}


void FirstWindow::wrapText(sf::Text& text, float maxWidth)
{
	std::string originalString = text.getString();
	std::string wrappedString;
	std::string currentLine;
	std::istringstream wordStream(originalString);
	std::string word;

	while (wordStream >> word) {
		sf::Text tempText = text;
		tempText.setString(currentLine + word + " ");
		if (tempText.getLocalBounds().width > maxWidth) {
			wrappedString += currentLine + "\n";
			currentLine = word + " ";
		}
		else {
			currentLine += word + " ";
		}
	}

	wrappedString += currentLine; // Add the last line
	text.setString(wrappedString);
}
//-------------------------------------------------------------------
