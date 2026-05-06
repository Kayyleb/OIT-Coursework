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

#include "Cell.h"

/**********************************************************************
* Purpose: This function will create our cell object, and then set it 
*          all to default states. 
*
* Precondition:
* No precondition.
*
* Postcondition:
* Will create our cells, our mines, and all core features of minesweeper
* 
************************************************************************/
Cell::Cell() : m_is_mine(false), m_is_revealed(false), m_is_marked(false), m_adjacent_mines(0)
{
}

/**********************************************************************
* Purpose: This function returns wether the current cell is a mine or not
*
* Precondition:
* No precondition.
*
* Postcondition:
* Will return if the current cell selected is a mine or not
* 
************************************************************************/
bool Cell::isMine() const 
{ 
    return m_is_mine; 
}

/**********************************************************************
* Purpose: This function returns wether the current cell is revealed or not
*
* Precondition:
* No precondition.
*
* Postcondition:
* Will return if the current cell selected is revealed or not
*
************************************************************************/
bool Cell::isRevealed() const 
{ 
    return m_is_revealed; 
}

/**********************************************************************
* Purpose: This function returns wether the current cell is marked or not
*
* Precondition:
* No precondition.
*
* Postcondition:
* Will return if the current cell selected is marked or not
*
************************************************************************/
bool Cell::isMarked() const 
{ 
    return m_is_marked; 
}

/**********************************************************************
* Purpose: This function returns the number of adjacent mines that are
*          around the selected cell
*
* Precondition:
* No precondition.
*
* Postcondition:
* Will return the number of adjacent mines that are around the selected 
* cell
*
************************************************************************/
int Cell::getAdjacentMines() const 
{ 
    return m_adjacent_mines; 
}

/**********************************************************************
* Purpose: This function sets the cell to wether it is a mine or not
*
* Precondition:
* No precondition.
*
* Postcondition:
* Will set the cell to the state of wether its a mine or not 
*
************************************************************************/
void Cell::setMine(bool is_mine) 
{ 
    m_is_mine = is_mine; 
}

/**********************************************************************
* Purpose: This function sets the cell to wether it is revealed or not
*
* Precondition:
* No precondition.
*
* Postcondition:
* Will set the cell to the state of wether its revealed or not
*
************************************************************************/
void Cell::setRevealed(bool is_revealed) 
{ 
    m_is_revealed = is_revealed; 
}

/**********************************************************************
* Purpose: This function sets the cell to wether it is marked as a bomb
*          or not
*
* Precondition:
* No precondition.
*
* Postcondition:
* Will set the cell to wether it is marked as a bomb or not 
*
************************************************************************/
void Cell::setMarked(bool is_marked) 
{ 
    m_is_marked = is_marked; 
}

/**********************************************************************
* Purpose: This function will set our cell, to the number of adjacent mines
*          are around it 
*
* Precondition:
* No precondition.
*
* Postcondition:
* Will set the cell to how many adjacent bombs are around the cell
*
************************************************************************/
void Cell::setAdjacentMines(int count) 
{ 
    m_adjacent_mines = count; 
}

/**********************************************************************
* Purpose: This function will return our cells current state as a variable, for
*          when the board class calls our display cell function 
*
* Precondition:
* Cells must exist and the game must work and be running for this to display anything
*
* Postcondition:
* Will return the current state of our cell as variables for when we call display
* onto the board. 
*
************************************************************************/
char Cell::getDisplayChar() const {
    if (!m_is_revealed) // if the cell isn't revealed
    {
        return m_is_marked ? 'M' : '?'; // if the cell is returned as marked, then 'M' is returned as the character for marked on the board
    }                                   // if the cell is returned as not marked, then '?' will be the character displayed for the board

    if (m_is_mine)                      // if the selected cell was a mine
    {
        return 'X';                     // return 'X' as the character for mines exploded 
    }

    if (m_adjacent_mines == 0)          // if theres no adjacent mines to the selected cell
    {
        return ' ';                     // then just return a blank character for nothing
    }

    return '0' + m_adjacent_mines;      // if there is adjacent mines, the return the amount of them
} 