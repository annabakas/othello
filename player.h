#ifndef _PLAYER_H_
#define _PLAYER_H_
#include "gameboard.h"

extern int valid_moves(othello_board_t *board,int moves[][SIZE], char player);
extern void prompt_move(int *row, int *col);
extern void print_possible_moves(int r, int c);
extern void init_moves(int moves[][SIZE]);
extern int avoid(int r, int c, int row_count, int col_count);
extern char set_opponent(char player);
extern void pass_move(char *again);
#endif
