#include "GameController.h"


//--------------------------------------------------------
void GameController::run()
{
	// ------ need do write this FirstWindow in private. ------
	FirstWindow firstWindow(m_SfmlManager);
	handleFirstWindow(firstWindow);
	if (firstWindow.need2exit())
		return;
	//---------------------------------------------------

	std::string fileName = "level01.txt";
	readAndAnalyze(fileName);

	//sf::Vector2f loc{ 0,0 };
	//  MovingObject tempObj(loc, m_SfmlManager, ObjName::E_Robot);
	//Robot robot(loc, m_SfmlManager); // Add semicolon here

	//loc.x += 8;
	//loc.y += 6;
	//Guard guard(loc, m_SfmlManager);

	//loc.x = 3;
	//loc.y = 9;
	//Guard guard2(loc, m_SfmlManager);

	//loc.x = 7;
	//Wall wall(loc, m_SfmlManager);

	sf::Clock gameClock;
	GameBoard gameBoard(m_width, m_height + 2);
	auto& window = gameBoard.getWindow();

	while (window.isOpen())
	{
		sf::Event event;
		if (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		/*robot.updateDirection(sf::Vector2f());
		guard.updateDirection(robot.getLocation());*/

		//*****
		sf::Vector2f robotLoc;
		for (const auto& objMov : m_movingObjVec) // to find location for robot
		{
			if (auto* robot = dynamic_cast<Robot*>(objMov.get()))
			{
				robotLoc = robot->getLocation();
				break;
			}
		}

		for (const auto& objMov : m_movingObjVec) {
			objMov->updateDirection(robotLoc);
		}
		//****
		auto deltaTime = gameClock.restart().asSeconds();
		for (const auto& objMov : m_movingObjVec)
		{
			objMov->move(deltaTime);
			handleCollisionController(*objMov); // call to function of this class.
		}
		//****
		
		 
		 
		//robot.move(deltaTime);
		//guard.move(deltaTime); // guard move to robot!
		//robot.handleCollision(guard);
		//robot.handleCollision(guard2);
		//robot.handleCollision(wall);

		window.clear();

		for (const auto& obj : m_movingObjVec) {
			obj->draw(window);
		}
		for (const auto& obj : m_staticObjVec) {
			obj->draw(window);
		}



		/*	robot.draw(window);
			guard.draw(window);
			guard2.draw(window);
			wall.draw(window);*/

		window.display();
	}
}


void GameController::handleCollisionController(MovingObject& movingObject)
{
	// call to function of StaticObject class
	for (const auto& obj : m_movingObjVec) // A moving object meets a moving object
	{
		if (movingObject.checkCollision(*obj)) // if (movingObject == obj) return false. else true
		{
			movingObject.handleCollision(*obj); // call to function of StaticObject class
			/*
			Function is correct both if a robot gets stuck in a guard and if the guard gets stuck in the robot
			*/
		}
	}

	for (const auto& obj : m_staticObjVec)  // A moving object meets a stationary object
	{
		if (movingObject.checkCollision(*obj)) //
		{
			movingObject.handleCollision(*obj);
		}
	}
}

void GameController::readAndAnalyze(std::string& fileName)
{
	auto file = std::ifstream(fileName);
	if (!file.is_open())
	{
		std::cerr << "Error: Cannot open file " << fileName << std::endl;
		return;
	}

	// Reset the rows and columns for each step.
	m_height = m_width = 0;

	// go to all line in file and update the vec.
	std::string line;
	while (getline(file, line))
	{
		updateThisLine(line);
		m_height++;
	}
	m_width = static_cast<unsigned int>(line.size());
}

void GameController::updateThisLine(std::string& line)
{
	char ch;
	for (int i = 0; i < line.size(); i++)
	{
		ch = line[i];
		analyzeObj(ch,i);
	}
}

void GameController::analyzeObj(char& ch ,int col)
{
	switch (ch)
	{
	case '/':
		m_movingObjVec.push_back(std::make_unique<Robot>(sf::Vector2f((float)col, (float)m_height), m_SfmlManager));
		break;
	case '!':
		m_movingObjVec.push_back(std::make_unique<Guard>(sf::Vector2f((float)col, (float)m_height), m_SfmlManager));
		break;
	case '#':
		m_staticObjVec.push_back(std::make_unique<Wall>(sf::Vector2f((float)col, (float)m_height), m_SfmlManager));
		break;
	case '@':
		m_staticObjVec.push_back(std::make_unique<Rock>(sf::Vector2f((float)col, (float)m_height), m_SfmlManager));
		break;
	case 'D':
		m_staticObjVec.push_back(std::make_unique<Door>(sf::Vector2f((float)col, (float)m_height), m_SfmlManager));
		break;
	}
}
//--------------------------------------------------------
void GameController::handleFirstWindow(FirstWindow& window) const
{
	window.customerChoice();

	if (window.need2exit())
	{
		std::cout << "Exiting For The Game \n";
	}
	else if (window.need2start())
	{
		std::cout << "Starting The Game\n";
	}
}
//--------------------------------------------------------
sf::Vector2f GameController::getDirection()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		return (sf::Vector2f{ 1, 0 });
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		return (sf::Vector2f{ -1, 0 });
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		return (sf::Vector2f{ 0, -1 });
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		return (sf::Vector2f{ 0, 1 });
	}
	else
		return (sf::Vector2f{ 0, 0 });


}