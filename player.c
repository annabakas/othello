#include "player.h"
#include <stdio.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void init_first_player(player_t *first) {
    char name[NAMELEN+1];

    printf("Enter name of Player 1: ");
    fgets(name,NAMELEN, stdin);
    strncpy(first -> name, name, NAMELEN);
    fflush(stdin);
    first -> token = 'W';
    first -> score = 0;
}

void init_second_player(player_t *second) {
    char name[NAMELEN+1];

    printf("Enter name of Player 2: ");
    fgets(name, NAMELEN, stdin);
    strncpy(second -> name, name, NAMELEN);
    second -> token = 'B';
    second -> score = 0;
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

int make_move(player_t *first) {
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

    if(is_valid_position(row, col) == 0) {
        printf("Coordinates are not valid. Please try again: \n");
    }
    return 0;
}

void swap_players(player_t **first, player_t **second){
	player_t *temp = *first;
	*first = *second;
	*second = temp;
	printf("Swap success\n");
}


