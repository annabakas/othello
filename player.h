#ifndef _PLAYER_H_
#define _PLAYER_H_
#include "gameboard.h"

extern int valid_moves(othello_board_t *board,int moves[][SIZE], char player);
extern void prompt_move(int *row, int *col);
#endif
