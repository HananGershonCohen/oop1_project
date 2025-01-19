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

	sf::Clock gameClock;
	sf::Vector2f loc{ 0,0 };
	 //  MovingObject tempObj(loc, m_SfmlManager, ObjName::E_Robot);
    Robot robot(loc, m_SfmlManager); // Add semicolon here
	GameBoard gameBoard(25, 20);

	loc.x += 8;
	loc.y += 6;
	Guard guard(loc, m_SfmlManager);

	auto& window = gameBoard.getWindow();
	sf::Vector2f direction{ 0,0 };

	while (window.isOpen())
	{
		sf::Event event;
		if (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();

			robot.updateDirection();
		}

		guard.updateDirection(robot.getLocation());

		auto deltaTime = gameClock.restart().asSeconds();

		robot.move(deltaTime);
		guard.move(deltaTime); // guard move to robot!
		
		

		window.clear();
		robot.draw(window);
		guard.draw(window);
		guard.draw(window);
		window.display();

	

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