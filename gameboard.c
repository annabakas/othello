#include "gameboard.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void othello_new(othello_board_t* board) {
    for(int x = 0; x < ROWS; x++) {
        for(int g = 0; g < COLS; g++) {
            board -> board[x][g] = '*';
        }
    }
}

void othello_init(othello_board_t* board) {
    board -> board[3][3] = 'X';
    board -> board[3][4] = '0';
    board -> board[4][3] = '0';
    board -> board[4][4] = 'X';
}

void print_othello(othello_board_t* board) {
    for(int x = 0; x < ROWS; x++) {
        for(int y = 0; y < COLS; y++) {
            printf("%c", board->board[x][y]);
        }
        printf("\n");
    }
}

void othello_copy(othello_board_t* board, othello_board_copy_t* copy_board) {
    memcpy(&copy_board, &board, sizeof(board));
    for(int x = 0; x < ROWS; x++) {
        for(int y = 0; y < COLS; y++) {
            printf("%c", copy_board -> copy_board[x][y]);
        }
        printf("\n");
    }
}

int main() {
    othello_board_t board;
    othello_board_copy_t copy_board;
    othello_new(&board);
    othello_init(&board);
    othello_copy(&board, &copy_board);
    printf("\n");
    print_othello(&board);
}



