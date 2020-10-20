#include "gameboard.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

othello_board_t *board[8][8];
othello_board_t *copy[8][8];
//Initializes gameboard with four center pieces
void othello_new() {
    for(int x = 0; x < ROWS; x++) {
        for(int g = 0; g < COLS; g++) {
            board[x][g] = malloc(sizeof(char*));
            if((x == 3 && g == 3) || (x == 4 && g == 4)) {
                board[x][g] -> color = 'W'; //Player A
            }
            else if((x == 3 && g == 4) || (x == 4 && g == 3)) {
                board[x][g] -> color = 'B'; //Player B
            }
            else {
                board[x][g] -> color = ' ';
            }
        }
    }
}

//Displays the board in current state with row numbers and column numbers
void displayBoard() {
    char col_label = '1';
    int col, row;

    for(col = 0; col < COLS; col++) {
        printf("   %c", col_label+col); //Display top line
    }
    printf("\n");

    //Display middle rows
    for(row = 0; row < ROWS; row++) {
        printf("  +");
        for(col = 0; col<COLS; col++) {
            printf("---+");
        }
        printf("\n%2d|",row + 1);

        for(col = 0; col<COLS; col++) {
            printf(" %c |", board[row][col]->color); //Display row counters
        }
        printf("\n");
    }

    printf("  +");
    for(col= 0 ; col<COLS ; col++) {
        printf("---+"); // Display bottom line
    }
    printf("\n");
}

//Copies othello board into another board
void copyBoard() {
    //othello_board_t *copy[8][8];
    for(int row = 0; row < ROWS; row++) {
        for(int col = 0; col < ROWS; col++) {
            copy[row][col] = board[row][col];
        }
    }

}

//Check if board is full
//Return 0 if not and 1 if it is
int board_full() {
    int x, y;
    for(x = 0; x < ROWS; x++) {
        for(y = 0; y < COLS; y++) {
            if(board[x][y] -> color  == ' ') {
                return 0;
            }
        }
    }
    return 1;
}

//See if position player entered is valid or not
int is_valid_position(int row, int col) {
    if(row < 0 || row >= 8 || col <0 || col >= 8) {
        return 0;
    }
    return 1;
}

//Comparing if two boards are identical
//Return 0 if they aren't and 1 if they are
//Prints the row and column where there are differences
int compareBoards() {
    int row = 0;
    int col = 0;
    for(row = 0; row < ROWS; row++) {
        for(col = 0; col < COLS; col++) {
            char b[3] = {board[row][col] -> color};
            char c[3] = {copy[row][col] -> color};
            if(board[row][col] -> color != copy[row][col] -> color) {
                printf("row: %d col: %d\n", row, col);
                return 0;
            }
        }
    }

    return 1;
}
