#ifndef _UTILTIY_H_
#define _UTILITY_H_

#include "player.h"
#include "gameboard.h"
#include "logic.h"

#include <stdio.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

extern void welcome();
extern int valid_choice(char letter);
extern char game_choice();
extern char get_winner(int playerA_Score, int playerB_Score);
extern int who_won(int playerA_Score, int playerB_Score);
extern int quit(othello_board_t *board, int invalid_moves);
extern int get_index(int x);
extern int getScore(othello_board_t *board, char player);
extern void display_score(int playerA_Score, int playerB_Score);
extern void display_current_player(char player);
extern void display_invalid_coords();
extern int gameOver(othello_board_t *board);

#endif
