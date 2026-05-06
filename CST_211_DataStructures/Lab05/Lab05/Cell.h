#pragma once
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
* Class: Cell
*
* Purpose: This class creates cells for the board, as in creates mines, 
*          checks if things are revealed or marked as well as count the 
*          number of adjacent mines.
*
* Manager functions:
*    Cell(); 
*        - Default ctor that creates, our cells for our board, will set
*         all outr data members to a default state
*
* Getters: 
*    bool isMine() const;
*      - Our isMine getter, will return back if the selected cell is a mine or not
* 
*    bool isRevealed() const;
*      - Our isRevealed getter, will return back if the selected cell is revealed or not
*
*    bool isMarked() const;
*      - Our isMarked getter, will return back if the selected cell is marked as a mine 
*
*    int getAdjacentMines() const;
*      - Our getAdjacentMines getter, will return back the number of adjacent mines
*        around the revealed mark
*
*   Setters: 
*    void setMine(bool is_mine);
*      - Our setMine setter, which will set our mines to the inputed state (inputed
*        with our board class) 
* 
*     void setRevealed(bool is_revealed);
*      - Our setRevealed setter, which will set our cells to the inputed revealed
*         state, as in not revealed or is reveleaed (inputed with our board class)
* 
*    void setMarked(bool is_marked);
*      - Our setMarked setter, which will set our cells to the inputed marked
*         state, as in not marked or is marked (inputed with our board class)
* 
*     void setAdjacentMines(int count);
*      - Our setAdjacentMines setter, which will be set to how many adjacent mines
*        are around the cell that was revealed
* 
*   Other Functions: 
*    char getDisplayChar() const;
*       - Displays the kind of state the current cell is set to, as in displays marked,
*         revealed. etc.
* 
*************************************************************************/

class Cell {
private:
    bool m_is_mine;
    bool m_is_revealed;
    bool m_is_marked;
    int m_adjacent_mines;

public:
    // Manager Functions
    Cell();
    
    // Getters
    bool isMine() const;
    bool isRevealed() const;
    bool isMarked() const;
    int getAdjacentMines() const;
    
    // Setters
    void setMine(bool is_mine);
    void setRevealed(bool is_revealed);
    void setMarked(bool is_marked);
    void setAdjacentMines(int count);
    
    // Display method
    char getDisplayChar() const;
};