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

/*************************************************************
*
* Lab/Assignment: Lab 5 – Minesweeper
*
* Overview: 
* The purpose of this program is to make the game minesweeper 
* by hand. We create a cell class to define all of the 'squares' (cells)
* this class will create the mines and everything as well. Then based
* off that cell class, we create the board class, which will create all functionality
* of the game. It will create a grid for the board made from our 2D 
* array class made in previous labs then will make sure the board can be 
* revealed at certain inputs, can take in other inputs as game functions
* (such as marking and revealing), creates and places the mines at random places, 
* checks for error inputs, coloring the different parts of the game, 
* and loosing/winning game condionals. The board class is the core of the program. 
* Then we have our minesweeper class, which tells our board class how to run the game. 
* It will pass through our inputs into board, such as difficulty level, reveal & mark input, 
* and loosing the game outputs. No class works without the other, and the entire program
* only functions together. 
* 
* Input:
* The program takes in these inputs:
*   - R for revealing a certain cell in the game
*   - M for marking a certain cell in the game
*   - U for unmarking an already marked cell in the game
*   - (R, C) for inputing the specific location you want to do any of the above commands to
* Input should look like this: r 0, 0
* This will reveal the cell at row 0, column 0
* 
* Before the game starts, it takes in the inputs 
*   - b (beginner)
*   - i (intermediate)
*   - e (expert)
* to take in the difficulty level desired
*
* Output:
* The output of the game will output a full grid of question marks
* The question marks are to indicate that the cell hasn't been revealed yet
* Then when a cell is revealed, it will either reveal all empty cells, then
* reveal the amount of 1 or 2 adjacent bombs, and color the number either green or blue.
* When a cell is marked, it will show an M, and then color it yellow
* When a bomb is found (and the game is loss) all bombs will be revealed, and bombs are
* marked with an X in red, as well as an game loss message is outputed. When the game is won, either by all 
* bombs being marked, or by all empty cells being revealed, and won output message is revealed. 
* 
************************************************************/

#define _CRTDBG_MAP_ALLOC
#include <iostream>
#include "Minesweeper.h"


/**********************************************************************
* Purpose: This function outputs to the consumer asking what difficulty they would 
*          like to choose before the game can run
*
* Precondition:
* All our classes must work & an input must be made to start anything
*
* Postcondition:
* Will input the level conditions and then send it to our board, and then create
* the board based of the difficulty level
*
************************************************************************/
void getBoardConfig(char level, int& rows, int& cols, int& mines) 
{
    switch (level) 
    {
    case 'b': // if input = b, set the board to difficulty beginner conditions
        rows = 10; cols = 10; mines = 10;  // beginner
        break;
    case 'i': // if input = i, set the board to difficulty intermediate conditions
        rows = 16; cols = 16; mines = 40;  // intermediate
        break;
    case 'e': // if input = e, set the board to difficulty expert conditions
        rows = 16; cols = 30; mines = 100; // expert
        break;
        // break statement are basically a return statement. If the input matches one of the cases, then break away from the switch loop
    }   
}

/**********************************************************************
* Purpose: This function will take in the difficulty level prompted above
*          then input it into our minesweeper class, and create the game 
*          with the select difficulty
*
* Precondition:
* Input must be chosen above
*
* Postcondition:
* Will input our difficulty level into our minesweeper class, and create the game 
* with the select difficulty
*
************************************************************************/
char getDifficultyLevel() 
{
    char level;
    do // do this, while the while loop continues
    {
        std::cout << "Select difficulty level (b/i/e): "; // prompt to choose difficulty
        std::cin >> level;                                // take in difficulty input
        level = tolower(level);                           // make whatever the input is lowercase
    } 
    while (level != 'b' && level != 'i' && level != 'e'); // keep outputting until one of the above is chosen
    return level;                                         // then return the input into our main
}

int main() 
{
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

    int rows, cols, mines;                      // define rows, cols, and mine variables
    char level = getDifficultyLevel();          // then get the difficulty input
    getBoardConfig(level, rows, cols, mines);   // send it to the board configuation function to create the board
    Minesweeper game(rows, cols, mines);        // now create the game based on the board inputs
    game.run();                                 // run the game
    return 0;
}