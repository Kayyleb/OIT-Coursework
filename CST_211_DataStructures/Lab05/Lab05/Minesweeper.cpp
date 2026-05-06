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

#include "Minesweeper.h"
#include <iostream>


/**********************************************************************
* Purpose: This function creates our Minesweeper game 'object,' and sets it
*          to the inputed difficulty level. 
*
* Precondition:
* No precondition other than the board class must be made and initialized for it
* to take in the difficulty perameters 
*
* Postcondition:
* Will create the game by calling board, and inputing the requirements for the game. Also sets
* our gameOver variable to false (default state) so the game can be ready to go when called
*
************************************************************************/
Minesweeper::Minesweeper(int rows, int cols, int mines) : gameOver(false), board(rows, cols, mines) 
{ 
}

/**********************************************************************
* Purpose: This function defines the correct input commands, and makes sure
*          any out of bounds, or junk inputs aren't taken in. 
*
* Precondition:
* Preconditions: 
*   - Input cannot be blank
*   - Cannot be over 10,000 characters
*
* Postcondition:
* Since the game is ran in the terminal, it will set the inputs needed to play the game
*   - R for reveal
*   - M for mark
*   - U for unmark
* and then input in the format "row, column" for where you want to do your action
*
************************************************************************/
bool Minesweeper::processCommand() 
{
    char command; // command char variable for all inputs 
    int row;      // row variable for input
    int col;      // column variable for input
    
    // Prompt to enter command
    std::cout << "\nEnter command (r for reveal, m for mark, u for unmark) and coordinates (row, col): ";
    std::cin >> command; // input the command you decide to enter
    
    if (std::cin.fail())                                    // if the input is junk, then it will fail 
    {
        std::cin.clear();                                   // if the input is blank
        std::cin.ignore(10000, '\n');                       // or if the input is 10000 characters long of junk
        std::cout << "Invalid input. Please try again.\n";  // output error message
        return true;                                        // set the fail to true, and return back
    }

    std::cin >> row;    // input the desired row
    char comma;
    std::cin >> comma;  // input a comma for readability
    std::cin >> col;    // input the desired column

    command = tolower(command); // turn whatever input was entered to lowercase so we don't have to have extra code to take in capital letters, or convert individually
    
    switch (command)    // switch statement that goes based on commands. A better if statement for inputs 
    {
    case 'r':           // if input = 'r'
        if (!board.isValidMove(row, col))                   // check if isnt a valid move
        {
            std::cout << "Invalid move. Try again.\n";      // if it isnt, output error message
            return true;                                    // then return true, that it is not a valid move
        }
        if (!board.revealCell(row, col))                    // check if the input was a mine or not
        {
            board.display(true);                            // if it was, then show all mines
            std::cout << "\nGame Over! You hit a mine!\n";  // output game over message
            return false;                                   //  return false, that the game is over
        }
        break;

    case 'm':  // if the input = 'm' then mark the cell
    case 'u':  // if the input = 'u' then unmark the cell
        board.toggleMark(row, col); // checks if the cell is marked already or not, then toggles mark on or off, depending if its marked or not already
        break;

    default: // default case, if any of the above cases arent met, then the input doesn't match game requirements  
        std::cout << "Invalid command. Use 'r' for reveal, 'm' for mark, or 'u' for unmark.\n"; // output error message
        return true; // return back true, that a bad input was inputed
    }

    board.display(false); // set the board display to false, so it doesn't display the whole board
    
    if (board.isGameWon()) // now if the gae is won
    {
        std::cout << "\nCongratulations! You've won!\n"; // output winning message
        board.display(true);                             // then display the board
        return false;                                    // return false, that game is over
    }
    return true;                                         // return true if not, that game continues
}

/**********************************************************************
* Purpose: This function runs our minesweeper game
*
* Precondition:
* Precondition is that all classes must be correctly initialized for the game to run
*
* Postcondition:
*Will start ot run our game but displaying the board, then running our input commands 
*
************************************************************************/
void Minesweeper::run() 
{
    board.display(false);        // Display default unrevealed board
    
    while (!gameOver)            // set game to not over
    {          
        if (!processCommand())   // if we return that the process commands are over
        { 
            gameOver = true;     // then game over
        }
    }
} 