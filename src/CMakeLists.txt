﻿file (GLOB_RECURSE MY_SOURCE_FILES CONFIGURE_DEPENDS LIST_DIRECTORIES false RELATIVE ${CMAKE_CURRENT_LIST_DIR} *.cpp)
target_sources (${CMAKE_PROJECT_NAME} PRIVATE ${MY_SOURCE_FILES} "../include/Windows.h" "Windows.cpp" "../include/GameController.h" "GameController.cpp" "../include/FirstWindow.h" "FirstWindow.cpp" "../include/ObjName.h"  "../include/SfmlManager.h" "SfmlManager.cpp" "../include/Button.h" "Button.cpp" "../include/GameBoard.h" "GameBoard.cpp" "../include/StaticObject.h" "StaticObject.cpp" "../include/Wall.h" "Wall.cpp" "../include/Guard.h" "guard.cpp" "../include/MovingObject.h" "MovingObject.cpp" "../include/Robot.h" "Robot.cpp" "../include/Door.h" "Door.cpp" "../include/Rock.h" "Rock.cpp" "../include/Bomb.h" "Bomb.cpp" "../include/CountdownTimer .h" "CountdownTimer .cpp" "../include/Gift.h" "../include/Gift1.h"  "../include/Gift3.h" "../include/Gift4.h" "Gift.cpp" "Gift1.cpp" "Gift3.cpp" "Gift2.cpp" "Gift4.cpp" "ObjName.cpp"  )




