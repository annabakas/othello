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

int heuristic(othello_board_t *board, char player);
void minimax(othello_board_t *board, int moves[][SIZE], char player);
int minimaxVal(othello_board_t *tempBoard, char origTurn, char currentTurn, int search);
#endif
