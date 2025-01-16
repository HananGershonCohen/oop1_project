#include "GameController.h"
//--------------------------------------------------------
void GameController::run()
{

	GameBoard gameBoard(0, 0);
	gameBoard.create(15, 15, 0);
	
	FirstWindow window(m_textureManager);
	handleFirstWindow(window);

	
}
//--------------------------------------------------------
void GameController::handleFirstWindow(FirstWindow& window) const
{
	window.customerChoice();

	if (window.need2exit())
	{
		std::cout << "Exiting For The Game \n";
		exit(0);

	}
	else if (window.need2start())
	{
		std::cout << "Starting The Game\n";
	}
}