#include "player.h"
#include <stdio.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void init_first_player(player_t *first) {
    char name[NAMELEN+1];

    printf("Enter name of Player 1: ");
    scanf("%s",name);
    strncpy(first -> name, name, NAMELEN);
    first -> token = 'W';
}

int valid_moves(int moves[][COLS], char player) {
    int rowInc = 0;
    int colInc = 0;
    int row = 0;
    int col = 0;
    int x = 0;
    int y = 0;
    int no_of_moves = 0;

    // Sets opponent
    char opponent = (player == 'W')? 'B' : 'W';

    //Initialize moves array to zero
    for(row = 0; row < 8; row++) {
        for(col = 0; col < 8; col++) {
            moves[row][col] = 0;
        }
    }


}

