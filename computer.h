#ifndef _COMPUTER_H_
#define _COMPUTER_H_

#include "player.h"
#include "gameboard.h"
#include "utility.h"
#include "logic.h"

#include <stdio.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void copy_board(othello_board_t *board, othello_board_t *tempBoard);
int heuristic(othello_board_t *board, char player);
int best(othello_board_t *board, int moves[][SIZE], char player, int search);
int set_high(int tempScore, int max);
void decision(othello_board_t *board, int moves[][SIZE], char player);

void minimax(othello_board_t *board, int moves[][SIZE], char player);
int minimaxVal(othello_board_t *tempBoard, char origTurn, char currentTurn, int search);
#endif
