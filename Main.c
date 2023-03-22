/*
    Main.c

    This program creates a tictactoe board and allows two players to keep track of the tictactoe game through the terminal.
    
    Jeremy Wei 3/12/23
*/

#include <stdio.h>
#include "TicTacToe.h"

int main(){
    char** board = mkBoard();
    char winner;
    int turn = -1;
    clrTerminal();
    printf("\nWelcome to TicTacToe! Player 1 goes first and they are 'X' \n");
    dispBoard(board);
    do{ /* Switch turns from each player until we have a winner */
        turn++;
        if(turn%2 == 0){
            promptUser(board, PLAYER_ONE);
        }else{
            promptUser(board, PLAYER_TWO);
        }
        dispBoard(board);
        winner = checkForWinner(board);
    }while(winner == '_');
    printf("Player %d wins in %d turns!! Well played! Here is the final board: \n", turn%2+1, turn+1);
    dispBoard(board);
    free(board);
    return 0;
}
