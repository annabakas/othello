#include "gameboard.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void othello_new(othello_board_t *board) {
    for(int x = 0; x < ROWS; x++) {
        for(int g = 0; g < COLS; g++) {
            board -> othello[x][g] = ' ';
        }
    }

    board -> othello[3][3] = 'X'; //Player 1
    board -> othello[3][4] = '0'; //Player 2
    board -> othello[4][3] = '0';
    board -> othello[4][4] = 'X';
}

void print_othello(othello_board_t *board) {
    char col_label = '1';
    int col, row;
    for(col = 0; col < COLS; col++) {
        printf("   %c", col_label+col);
    }
    printf("\n");

    for(row = 0; row < ROWS; row++) {
        printf("  +");
        for(col = 0; col<COLS; col++) {
            printf("---+");
        }
        printf("\n%2d|",row + 1);

        for(col = 0; col<COLS; col++) {
            printf(" %c |", board->othello[row][col]);
        }
        printf("\n");
    }

    printf("  +");
    for(col= 0 ; col<COLS ; col++) {
        printf("---+");
    }
    printf("\n");
}

void othello_copy(othello_board_t* board, othello_board_copy_t* copy_board) {
    memcpy(&copy_board, &board, sizeof(board));
    for(int x = 0; x < ROWS; x++) {
        for(int y = 0; y < COLS; y++) {
            copy_board -> copy_board[x][y];
        }
    }
}

int board_full(othello_board_t *board) {
    int x, y;
    for(x = 0; x < ROWS; x++) {
        for(y = 0; y < COLS; y++) {
            if(board -> othello[x][y] == '*') {
                return 0;
            }
        }
    }

    return 1;
}

