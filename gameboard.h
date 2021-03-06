#ifndef _GAMEBOARD_H_
#define _GAMEBOARD_H_

#include <stdio.h>
#define SIZE 8
#define PLAYER_A 'A'
#define PLAYER_B 'B'
#define EMPTY ' '
#define PLAYABLE '*'

typedef struct _othello_board_t {
    char board[SIZE][SIZE];
} othello_board_t;

extern void othello_new(othello_board_t *board);

extern void displayBoard(othello_board_t *board);

extern int board_full(othello_board_t *board);

extern int is_valid_position(int row, int col);

extern void playable_squares(othello_board_t *board, int r, int c);

extern void clear_playable(othello_board_t *board);

extern void copy_board(othello_board_t *board, othello_board_t *tempBoard);
#endif

