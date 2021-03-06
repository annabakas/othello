#include "gameboard.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>


//Initializes gameboard with four center pieces
void othello_new(othello_board_t *board) {
    for(int x = 0; x < SIZE; x++) {
        for(int g = 0; g < SIZE; g++) {
            if((x == 3 && g == 3) || (x == 4 && g == 4)) {
                board -> board[x][g]  = PLAYER_A; //Player A
            }
            else if((x == 3 && g == 4) || (x == 4 && g == 3)) {
                board -> board[x][g] = PLAYER_B; //Player B
            }
            else {
                board -> board[x][g] = EMPTY;
            }
        }
    }
}

//Displays the board in current state with row numbers and column numbers
void displayBoard(othello_board_t *board) {
    char col_label = '1';
    int col, row;

    for(col = 0; col < SIZE; col++) {
        printf("   %c", col_label+col); //Display top line
    }
    printf("\n");

    //Display middle rows
    for(row = 0; row < SIZE; row++) {
        printf("   ");
        for(col = 0; col<SIZE; col++) {
            printf("----");
        }
        printf("\n%2d|",row + 1);

        for(col = 0; col<SIZE; col++) {
            printf(" %c |", board -> board[row][col]); //Display row counters
        }
        printf("\n");
    }

    printf("   ");
    for(col= 0 ; col<SIZE ; col++) {
        printf("----"); // Display bottom line
    }
    printf("\n");
}

//Check if board is full
//Return 0 if not and 1 if it is
int board_full(othello_board_t *board) {
    int x, y;
    for(x = 0; x < SIZE; x++) {
        for(y = 0; y < SIZE; y++) {
            if(board -> board[x][y]  == ' ') {
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

//Mark playable squares on the board with *
void playable_squares(othello_board_t *board, int r, int c) {
    for(int row = 0; row < SIZE; row++) {
        for(int col = 0; col < SIZE; col++) {
            board -> board[r][c] = PLAYABLE;
        }
    }
}

//Clear playable squares from the board
//after player makes their move
//Mark the squares empty
void clear_playable(othello_board_t *board) {
    for(int row = 0; row < SIZE; row++) {
        for(int col = 0; col < SIZE; col++) {
            if(board -> board[row][col] == PLAYABLE) {
                board -> board[row][col] = EMPTY;
            }
        }
    }
}

//Make copy of board
void copy_board(othello_board_t *board, othello_board_t *tempBoard) {
    for(int row = 0; row < SIZE; row++) {
        for(int col = 0; col < SIZE; col++) {
            tempBoard -> board[row][col] = board -> board[row][col];
        }
    }
}
