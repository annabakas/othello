#include "player.h"
#include "gameboard.h"
#include "logic.h"

#include <stdio.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

extern char get_winner(int playerA_Score, int playerB_Score);
extern int quit(othello_board_t *board, int invalid_moves);
extern int get_index(int x);
extern int getScore(othello_board_t *board, char player);
extern void display_score(int playerA_Score, int playerB_Score);
extern void display_current_player(char player);
extern void display_invalid_coords();
