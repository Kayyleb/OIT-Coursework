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

#include "Board.h"
#include <iostream>
#include <windows.h>

// Define color constants
const int COLOR_RED = FOREGROUND_RED | FOREGROUND_INTENSITY;                       // Bright Red for mines
const int COLOR_YELLOW = FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY; // Bright Yellow for markers
const int COLOR_ONE = FOREGROUND_GREEN | FOREGROUND_INTENSITY;                     // Bright Green for 1s
const int COLOR_TWO = FOREGROUND_BLUE | FOREGROUND_INTENSITY;                      // Bright Blue for 2s

/**********************************************************************
* Purpose: This function creates our board object, and sets it to our inputed difficulty requirements
*
* Precondition:
* Other classes must be intialized for our board to be created
*
* Postcondition:
* Creates our board for our game with our:
*   set grid size
*   number of mines
*   and sets the first move to a default state, as in true
*
************************************************************************/
Board::Board(int rows, int cols, int num_mines) :m_grid(rows, cols), m_rows(rows), m_cols(cols), m_num_mines(num_mines), m_first_move(true)
{
}

/**********************************************************************
* Purpose: This function checks if the current input is a valid position or not
*
* Precondition:
* Cells must exist, and the board must be created for this to even work
* 
* Postcondition:
* Will return back if the current input is a valid position on the board or not
*
************************************************************************/
bool Board::isValidPosition(int row, int col) const 
{
    return row >= 0 && row < m_rows && col >= 0 && col < m_cols;
    // return if row input is greater than zero && less than the current amount of rows
    // return if column input is greater than zero && less than the current amount of columns
}

/**********************************************************************
* Purpose: This function will place our mines at a bunch of random parts around the grid
*
* Precondition:
* Cells must exist, and there cannot be a mine placed in the same slot already
*
* Postcondition:
* Will place a  mine in a random cell, and then increment the counters for number of mines
* and then will calculate the number of adjacent mines to the specified cell 
*
************************************************************************/
void Board::placeMines(int first_row, int first_col) 
{
    int mines_placed = 0; // counter for number of mines placed 
    while (mines_placed < m_num_mines) // loop until number of mine requirement is reached
    {
        int row = rand() % m_rows;     // pick a random row out of the set amount of rows
        int col = rand() % m_cols;     // pick a random column out of the set amount of columns 

                                                
        if (m_grid.Select(row, col).isMine()) // check if there's already a mine placed in the chosen spot
        {
            continue;                          // if there is continue 
        }
        m_grid.Select(row, col).setMine(true); // if there isnt, then set a mine in that square 
        mines_placed++;                        // increment the counter
    }
    calculateAdjacentMines();                  // now we call the function that calculates thw adjacent mines 
}

/**********************************************************************
* Purpose: This function calculates the adjacent mines of a certain cell
*
* Precondition:
* Cells must exist, and it must be in a valid position.
*
* Postcondition:
* Will calculate the number of adjacent mines to a specified cell
*
************************************************************************/
void Board::calculateAdjacentMines() 
{
    for (int row = 0; row < m_rows; row++) 
    {
        for (int col = 0; col < m_cols; col++)               // loop through the grid 
        {             
            if (m_grid.Select(row, col).isMine()) continue;  // if the selected cell is a mine, then continue 

            int count = 0;
                                                             // Check all 8 adjacent cells
            for (int dr = -1; dr <= 1; dr++)                 // these loops are going to circle around all eight adjacent cells around a selected one
            {         
                for (int dc = -1; dc <= 1; dc++) 
                {           
                    if (dr == 0 && dc == 0) continue;        // if the loop reaches it's end, and gets to the middle(selected cell), 
                    
                    int new_row = row + dr;                  // this will move to the next row
                    int new_col = col + dc;                  // this will move to the next column
                    
                                                             // if this next row and column is a valid position, and is a mine
                    if (isValidPosition(new_row, new_col) && m_grid.Select(new_row, new_col).isMine()) 
                    {
                        count++;                             // then increment the mine count
                    }
                }
            }
            m_grid.Select(row, col).setAdjacentMines(count); // now set the number of adjacent mines to the selected cell to the number of mines that are there
        }
    }
}

/**********************************************************************
* Purpose: This function reveals an inputed cell 
*
* Precondition:
* Cells must exist, and input must be a valid position.
*
* Postcondition:
* Will reveal a cell wether its a bomb, a free space, or anything.
*
************************************************************************/
bool Board::revealCell(int row, int col) 
{   // If input is NOT a valid position OR is already revealed OR is already marked as a bomb
    if (!isValidPosition(row, col) || m_grid.Select(row, col).isRevealed() || m_grid.Select(row, col).isMarked()) 
    {
        return true;                                        // then return true 
    }

    if (m_first_move) {                                     // if its the first move
        placeMines(row, col);                               // place mines after first move
        m_first_move = false;                               // then set the first move to false, cause it isnt anymore
    }

    m_grid.Select(row, col).setRevealed(true);              // set the input to revealed after inputing 

    if (m_grid.Select(row, col).isMine()) {                 // if the input is a mine
        return false;                                       // Game Over                         
    }

    if (m_grid.Select(row, col).getAdjacentMines() == 0) {  // if the input has no adjacent cells
        revealEmptyCells(row, col);                         // reveal around the input until cells are inputed
    }

    return true;                                            // return true
}

/**********************************************************************
* Purpose: This function reveals empty cells
*
* Precondition:
* Cells must exist
* 
* Postcondition:
* Will reveal empty cells when we input a cell that has no bombs around it
* loops around the input cell, then reveals everything until it finds a bomb
* somewhere 
*
************************************************************************/
void Board::revealEmptyCells(int row, int col) 
{
    for (int dr = -1; dr <= 1; dr++) 
    {        
        for (int dc = -1; dc <= 1; dc++)        // loop around the input cell
        {      
            if (dr == 0 && dc == 0) continue;   // if the loop ends, then continue on 
            
            int new_row = row + dr;             // check the next row
            int new_col = col + dc;             // check the next column
            
            // if the new row and column is valiid & isnt revealed & isn't already marked
            if (isValidPosition(new_row, new_col) && !m_grid.Select(new_row, new_col).isRevealed() && !m_grid.Select(new_row, new_col).isMarked()) 
            {
                revealCell(new_row, new_col);   // then we will reveal the cells around
            }
        }
    }
}

/**********************************************************************
* Purpose: This marks an input cell
*
* Precondition:
* Cells must exist, be in range, and cannt already be revealed
*
* Postcondition:
* Will Mark the input as a bomb
*
************************************************************************/
void Board::toggleMark(int row, int col) 
{
    // if the input isnt a valid position OR is already revealed
    if (!isValidPosition(row, col) || m_grid.Select(row, col).isRevealed()) 
    {
        return; // return, cannot mark
    }
    
    // if not, then MArk that input 
    m_grid.Select(row, col).setMarked(!m_grid.Select(row, col).isMarked());
}

/**********************************************************************
* Purpose: This checks if the game is won or not
*
* Precondition:
* All bombs must be marked OR all cells must be revealed (not bombs)
*
* Postcondition:
* Will determine if the game is won or not
*
************************************************************************/
bool Board::isGameWon() 
{
    for (int row = 0; row < m_rows; row++) 
    {
        for (int col = 0; col < m_cols; col++)          // loop through the grid
        {        
            const Cell& cell = m_grid.Select(row, col); // set a new Cell variable to the column and row as it loops through
            if (!cell.isMine() && !cell.isRevealed())   // if that cell isn't a mine && if it isn't revealed
            { 
                return false;                           // game isnt won yet / not finished
            }
        }
    }
    return true;                                        // game is won
}

/**********************************************************************
* Purpose: This function will display everything about the game onto the screen
*
* Precondition:
* Everything else must be defined, and must work correctly for things to be defined
* 
* Postcondition:
* Will output our board, provide color for specific symbols, and make sure the game
* is playable by eye. It will provide the color green for adjacent bombs = 1, and blue 
* for adjacent bombs = 2. Then red for bombs, and a yellow marker for the 'M'
* Everything will be more visually readable and appealing with color.
*
************************************************************************/
void Board::display(bool show_mines) 
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    
                                                // Display column numbers
    std::cout << "   ";                         // Output blanks
    for (int col = 0; col < m_cols; col++)      // Loop thrpugh columns on thw board
    {
        std::cout << col % 10 << " ";           // now output the columns
    }
    std::cout << "\n";                          

                                                // Display the grid
    for (int row = 0; row < m_rows; row++) 
    {
        std::cout << row % 10 << "  ";          // Output the Row numbers
        for (int col = 0; col < m_cols; col++)  // loop through the columns
        {
            const Cell& cell = m_grid.Select(row, col); // create a new Cell object, and set it to the column and rows selected 
            if (show_mines && cell.isMine())            // if that cell is a min when displayed
            {
                SetConsoleTextAttribute(hConsole, COLOR_RED); // make it red
                std::cout << "X ";                            // display mine  
            } 
            
            else if (cell.isMarked())                               // if the cell is a mine, but is marked
            {
                SetConsoleTextAttribute(hConsole, COLOR_YELLOW);    // make the M yellow
                std::cout << "M ";                                  // display the marker    
            } 
            
            else if (cell.isRevealed())                             // if the cell is revealed 
            { 
                int adjacentMines = cell.getAdjacentMines();        // make a new adjacent mine int
                if (adjacentMines == 1)                             // if the number of adjacent mines is 1
                {
                    SetConsoleTextAttribute(hConsole, COLOR_ONE);   // Make '1' the color green
                    std::cout << "1 ";                              // Display 1 in green
                } 
                
                else if (adjacentMines == 2)                        // if the number of adjacent mines is 2
                {
                    SetConsoleTextAttribute(hConsole, COLOR_TWO);   // make the '2' blue
                    std::cout << "2 "; // Display 2 in bright blue  // Display the 2 blue 
                } 
                
                else                                                // If none of the above, as in the game normally
                {
                    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                    std::cout << cell.getDisplayChar() << " ";      // Display the blank 
                }
            } 
            
            else 
            {
                // If the cell is not revealed, display a placeholder
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE); // Default color
                std::cout << "? "; // '?' for unrevealed cells
            }
        }
        std::cout << "\n";
    }
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE); // Reset to default color
}

/**********************************************************************
* Purpose: This checks if the move inputed is valid or not
*
* Precondition:
* No precondition
*
* Postcondition:
* calls the function validPosition at the input, to make sure the input is on the board,
* then makes sure that the input isn't already revealed
*
************************************************************************/
bool Board::isValidMove(int row, int col) {
    return isValidPosition(row, col) && !m_grid.Select(row, col).isRevealed();
} 