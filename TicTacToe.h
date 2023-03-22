/*
    TicTacToe.h

    This file serves as a headerfile for the TicTacToe project.

    Jeremy Wei 3/12/23
*/

#include <stdio.h>
#include <stdlib.h>
#include "TicTacToe.c"
#define PLAYER_ONE 0
#define PLAYER_TWO 1

/*
    Uses malloc twice to create a 2D array of char storing the placement of markers on the board.
    Returns an empty board with '_' in each element.  
*/
char** mkBoard();

/*
    Displays the tictactoe board
*/
void dispBoard(char** boardPtr);

/*
    Prints a bunch of new lines to clear the terminal. 
*/
void clrTerminal();

/*
    Checks if a position on the board is empty. 
    Returns 0 if space is occupied by player marker, 1 otherwise. 
*/
int isEmpty(char** board, int row, int col);

/*
    Checks each winning condition and returns the winning marker if a win is detected. 
*/
char checkForWinner(char** board);