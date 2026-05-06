/*************************************************************
* Author: Kayleb Cook
* Filename: Lab05.cpp
* Date Created: 1/23/25
* Modifications:
*	1/23/25 - Created classes & started to set up cell class
*	1/24/25 - Finished cell class & started board class
*	1/25/25 - Finished board class & started working on minesweeper
*	1/26/25 - Applied finishing touches such as headers and cleaning
*			  up code
*
**************************************************************/

/************************************************************************
* Class: Minesweeper
*
* Purpose: This class' functionality is to make sure the game runs as expected,
* and put together the board and cell classes to make the minesweeper game
* function.
*
* Manager functions:
* bool processCommand();
*    - Defines all of our input commands, and sets restrictions and safety nets
*      for all inputs 
* 
* Minesweeper(int rows, int cols, int mines);
*    - Constructor for setting the difficulty of the game and creating the game 'object'
* 
* void run()
*    - Function for running the game
*
*
*************************************************************************/

#pragma once
#include "Board.h"

class Minesweeper {
private:
    Board board;
    bool gameOver;
    
    // Helper methods
    bool processCommand();
    
public:
    Minesweeper(int rows, int cols, int mines);  // Constructor
    void run();     // Main game loop
}; 