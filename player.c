#include "player.h"
#include <stdio.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void init_first_player(player_t *first) {
    char name[NAMELEN+1];
    int len = 0;
    printf("Enter name of Player 1: ");
    fgets(name,NAMELEN, stdin);
    len = strlen(name);
    if(name[len-1] == '\n') {
        name[len-1] = 0;
    }
    strncpy(first -> name, name, NAMELEN);
    first -> token = 'W';
    first -> score = 0;
}

void init_second_player(player_t *second) {
    char name[NAMELEN+1];
    int len = 0;
    printf("Enter name of Player 2: ");
    fgets(name, NAMELEN, stdin);
    if(name[len-1] == '\n') {
        name[len-1] = 0;
    }
    strncpy(second -> name, name, NAMELEN);
    second -> token = 'B';
    second -> score = 0;
}

int apply_move(player_t *first, othello_board_t *board, int x, int y, char token) {

}
int make_move(player_t *first, othello_board_t *board) {
    char x[10];
    char y[10];
    int row, col;
    int valid = 0;


    printf("Enter x coordinate for the piece you want to place: ");
    fgets(x,10,stdin);

    printf("Enter y coordinate for the piece you want to place: ");
    fgets(y,10,stdin);

    row = atoi(x);
    row--;
    col = atoi(y);
    col --;

    if(is_valid_position(row, col) != 0) {
        apply_move(first, board, row, col, first -> token);
    }
    return 0;
}

void swap_players(player_t **first, player_t **second) {
    player_t *temp = *first;
    *first = *second;
    *second = temp;
}


