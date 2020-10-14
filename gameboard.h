#ifndef _GAMEBOARD_H_
#define _GAMEBOARD_H_

#include <stdio.h>
#define ROWS 8
#define COLS 8

typedef struct _othello_board_t {
    char color;
}othello_board_t;

typedef struct _othello_board_copy_t {
    char copy_board[ROWS][COLS];
} othello_board_copy_t;

extern othello_board_t* othello[ROWS][COLS];

extern void othello_new();

extern void othello_copy();

extern void print_othello();

extern int board_full();

#endif

