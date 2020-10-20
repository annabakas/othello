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
    int pieces_captured = 0;
    int current_row = 0;
    int current_col = 0;
    int row, col;
    
    for(row = -1; row < 2; row++) {
        for(col = -1; col < 2; col++) {
            //Skipping initial pieces
            if(row != 0 || col != 0) {
                current_row = x + row;
                current_col = y + col;

                if(board[current_row][current_col] -> color != token && board[current_row][current_col] -> color != ' ' && (current_row > 0 && current_row < 8 && current_col > 0 && current_col< 8)) {
                    while(board[current_row][current_col] -> color != token && board[current_row][current_col] -> color != ' ' && (current_row > 0 && current_row < 8 && current_col > 0 && current_col < 8)) {
                        current_row = current_row + row;
                        current_col = current_col + col;
                    }
                    if(board[current_row][current_col] -> color == token) {
                        board[x][y] -> color = token;
                        while(current_row != x || current_col != y) {
                            current_row = current_row - row;
                            current_col = current_col - col;
                            board[current_row][current_col] -> color = token;
                            pieces_captured++;
                        }
                    }
                }
            }
        }
    }
    if(pieces_captured > 0) {
        return 1;
    }
    else {
        return 0;
    }
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
        if(apply_move(first, board, row, col, first -> token) == 1){
		valid = 1;
	}
	else{
		printf("There are no valid pieces to capture with the x,y that you entered.\n");
	}
    }
    else{
	    printf("Coordinates are not valid. Please try again: \n");
    }
    return 1;
}

void swap_players(player_t **first, player_t **second) {
    player_t *temp = *first;
    *first = *second;
    *second = temp;
}


