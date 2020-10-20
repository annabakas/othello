#ifndef _PLAYER_H_
#define _PLAYER_H_
#include "gameboard.h"
#define NAMELEN 20
typedef struct _player_t {
    char name[NAMELEN+1];
    char token;
    int score;
} player_t;

extern void init_first_player(player_t *first);
extern void init_second_player(player_t *second);

extern int valid_move(int moves[][8], char player);
extern int make_move(player_t *first, othello_board_t *board);
extern void swap_players(player_t **first,player_t **second);
extern int apply_move(player_t *first, othello_board_t *board, int x, int y, char token);
#endif
