#ifndef _GAMEBOARD_H_
#define _GAMEBOARD_H_

#include <stdio.h>
#define ROWS 8
#define COLS 8

typedef struct _othello_board_t{
	char board[ROWS][COLS];
}othello_board_t;


extern void othello_new(othello_board_t *board);;

extern void print_othello(othello_board_t *board);

#endif

