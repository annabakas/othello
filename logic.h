#include "player.h"
#include "gameboard.h"

#include <stdio.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

extern void make_move(othello_board_t *board, int r, int c, char player);
extern char get_winner(int playerA_Score, int playerB_Score);
