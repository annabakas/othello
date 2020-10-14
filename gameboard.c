#include "gameboard.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

othello_board_t* othello[8][8];

//Initializes gameboard with four center pieces
void othello_new(othello_board_t *board) {
    for(int x = 0; x < ROWS; x++) {
        for(int g = 0; g < COLS; g++) {
            othello[x][g] = malloc(sizeof(char*));
	    if((x == 3 && g == 3) || (x == 4 && g == 4)){
		    othello[x][g] -> color = 'X'; //Player A
	    }
	    else if((x == 3 && g == 4) || (x == 4 && g == 3)){
		    othello[x][g] -> color = '0'; //Player B
	    }
	    else{
		    othello[x][g] -> color = ' ';
	    }
        }
    }
}

//Prints gameboard
void print_othello() {
    char col_label = '1';
    int col, row;

    for(col = 0; col < COLS; col++) {
        printf("   %c", col_label+col); //Display top line
    }
    printf("\n");

    //Display middle rows
    for(row = 0; row < ROWS; row++) {
        printf("  +");
        for(col = 0; col<COLS; col++) {
            printf("---+");
        }
        printf("\n%2d|",row + 1);

        for(col = 0; col<COLS; col++) {
            printf(" %c |", othello[row][col]->color); //Display row counters
        }
        printf("\n");
    }

    printf("  +");
    for(col= 0 ; col<COLS ; col++) {
        printf("---+"); // Display bottom line
    }
    printf("\n");
}

int board_full() {
    int x, y;
    for(x = 0; x < ROWS; x++) {
        for(y = 0; y < COLS; y++) {
            if(othello[x][y] -> color  == ' ') {
                return 0;
            }
        }
    }

    return 1;
}

