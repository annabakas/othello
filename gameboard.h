#ifndef _GAMEBOARD_H_
#define _GAMEBOARD_H_

#include <stdio.h>
#define ROWS 8
#define COLS 8

typedef struct _othello_board_t {
    char othello[ROWS][COLS];
} othello_board_t;

typedef struct _othello_board_copy_t {
    char copy_board[ROWS][COLS];
} othello_board_copy_t;


extern void othello_new(othello_board_t *board);;

extern void othello_copy(othello_board_t* board, othello_board_copy_t* copy_board);

extern void print_othello(othello_board_t *board);

extern int board_full(othello_board_t *board);

#endif

