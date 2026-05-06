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
* Class: Board
*
* Purpose: Creates the board of the minesweeper game, and creates all the
*          necessary functions of the game
*
* Manager functions:
*    void placeMines(int first_row, int first_col);
*        - Places our mines into random slots around the grid
* 
*    void calculateAdjacentMines();
*        - Will calculate the number of Adjacent mines around the selected cell
*          
*    bool isValidPosition(int row, int col) const;
*        - Makes sure the position is valid, and not out of bounds
* 
*    void revealEmptyCells(int row, int col);
*        - Iterates around a selected cell and reveals around it  
*
*    Board(int rows, int cols, int num_mines);
*        - Creates the board with the inputed variables, only takes inputed variables
*          for the difficulty levels
*
*    bool revealCell(int row, int col);  // Returns false if mine is hit
*        - will reveal a cell at whatever is inputed
* 
*    void toggleMark(int row, int col);
*        - will mark a cell
*
*    bool isGameWon();
*        - Returns if game is won or not
* 
*    bool isValidMove(int row, int col);
*        - Makes sure what is inputed was a valid move or not
*
*    int getRows() const; 
*        - returns the number of rows
* 
*    int getCols() const;
*        - returns the number of columns
* 
*    int getNumMines() const;
*        - returns the number of mines 
*
*    void display(bool show_mines = false);
*        - our display function for the board
*
*************************************************************************/

#pragma once
#include "Array2D.h"
#include "Cell.h"
#include <random>

class Board {
private:
    Array2D<Cell> m_grid;
    int m_rows;
    int m_cols;
    int m_num_mines;
    bool m_first_move;

    // Helper methods
    void placeMines(int first_row, int first_col);
    void calculateAdjacentMines();
    bool isValidPosition(int row, int col) const;
    void revealEmptyCells(int row, int col);

public:
    // Constructor for different difficulty levels
    Board(int rows, int cols, int num_mines);

    // Game actions
    bool revealCell(int row, int col);  // Returns false if mine is hit
    void toggleMark(int row, int col);
    
    // Game state checks
    bool isGameWon();
    bool isValidMove(int row, int col);
    
    // Getters
    int getRows() const { return m_rows; }
    int getCols() const { return m_cols; }
    int getNumMines() const { return m_num_mines; }
    
    // Display
    void display(bool show_mines = false);
}; 