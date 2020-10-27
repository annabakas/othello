#include "player.h"
#include "gameboard.h"

#include <stdio.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

extern void make_move(othello_board_t *board, int r, int c, char player);
extern char get_winner(int playerA_Score, int playerB_Score);
extern int off_board(int x, int y);
extern int found_blank(othello_board_t *board, int x, int y);
extern void flip_pieces(othello_board_t *board, int x, int y, int row_count, int col_count, char other, char player);
extern void place_piece(othello_board_t *board, int r, int c, char player);
