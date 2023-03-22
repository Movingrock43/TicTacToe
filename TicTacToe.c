/*
    TicTacToe.c

    This file contains all function implementations for the TicTacToe project. 

    Jeremy Wei 3/12/23
*/

char** mkBoard(){
    char** boardPtr = (char**)malloc(3*(sizeof(char)));
    if(boardPtr == NULL){
        printf("\nFailed to allocate memory when instansiating the board!\n");
        return NULL;
    }
    int i;
    for(i = 0; i < 3; i++){
        boardPtr[i] = (char*)malloc(3*(sizeof(char)));
        if(boardPtr[i] == NULL){
            printf("\nFailed to allocate memory when instansiating the board!\n");
            return NULL;
        }
        int j;
        for(j = 0; j < 3; j++){
            boardPtr[i][j] = '_';
        }
    }
    return boardPtr;
}

void dispBoard(char** boardPtr){
    int i;
    printf("\n");
    printf("  1 2 3 \n");
    for(i = 0; i < 3; i++){
        printf("%d %c %c %c |\n", i+1, boardPtr[i][0], boardPtr[i][1], boardPtr[i][2]);
    }
    printf("\n");
}

void clrTerminal(){ /* You can change spaceNum to make more space or less space */
    int spaceNum = 1000;
    int i;
    for(i = 0; i<spaceNum; i++){
        printf("\n");
    }
}

int isEmpty(char** board, int row, int col){ /* Returns 1 if empty (space character) 0 otherwise */
    if(board[row][col] != '_'){
        return 0;
    }
    return 1;
}

char checkForWinner(char** board){
    int i, j;
    int winner = -1;
    /* 
        Values stores where each player has a marker on the board. 1 if there is a player marker, 0 if not.
        I did this so I can use boolean algebra to find a win.  
    */
    int values[2][3][3] = {{{0, 0, 0}, {0, 0, 0}, {0, 0, 0}}, {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}}};
    for(i = 0; i<3; i++){ /* Writes 1's to the corresponding elements of values. */
        for(j = 0; j<3; j++){
            if(board[i][j] == 'X'){
                values[0][i][j] = 1;
            }else if(board[i][j] == 'O'){
                values[1][i][j] = 1;
            }
        }
    }

    for(i = 0; i<2; i++){
        int rowMatch = 0, colMatch = 0, diagMatch = 0;
        for(j = 0; j<3; j++){ /* Checks for row and column 3-in-a-rows */
            rowMatch += values[i][j][0]*values[i][j][1]*values[i][j][2];
            colMatch += values[i][0][j]*values[i][1][j]*values[i][2][j];
        }
        /* Checks for diagonal matches */
        diagMatch = values[i][0][0]*values[i][1][1]*values[i][2][2] + values[i][2][0]*values[i][1][1]*values[i][0][2];
        if(rowMatch >= 1 || colMatch >= 1 || diagMatch >= 1){ /* Stops search if a win is found. */
                winner = i;
                break;
        }
    }
    if(winner == 0){
        return 'X';
    }else if(winner == 1){
        return 'O';
    }else{
        return '_';
    }
}

void promptUser(char** board, int playerNum){
    int row, col, empty;
    char marker;
    if(playerNum == 0){
        marker = 'X';
    }else if(playerNum == 1){
        marker = 'O';
    }else{
        marker = 'E';
    }
    printf("Player %d's turn! What row do you want to place your marker (%c)? Enter a value from 1-3: ", playerNum+1, marker);
    do{
        scanf("%d", &row);
        while(!(row >= 1 && row <= 3)){
            printf("Not a valid choice! Choose a number from  1-3: ");
            scanf("%d", &row);
        }
        printf("Now what column do you want to place your marker? Enter a value from 1-3: ");
        scanf("%d", &col);
        while(!(col >= 1 && col <= 3)){
            printf("Not a valid choice! Choose a number from  1-3: ");
            scanf("%d", &col);
        }
        empty = isEmpty(board, row-1, col-1);
        if(empty == 0){
            printf("The spot (%d, %d) is already taken! Choose another position. ", row, col);
            printf("Here is what the board looks like: \n");
            dispBoard(board);
            printf("(You are '%c') What row do you want to place your marker? Enter a value from 1-3: ", marker);
        }
    }while(empty == 0);
    board[row-1][col-1] = marker;
}
