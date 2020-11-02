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

void copy_board(othello_board_t *board, char tempBoard[SIZE][SIZE]);
int heuristic(othello_board_t *board, char player);

#endif
