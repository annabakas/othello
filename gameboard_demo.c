#include <stdio.h>
#include <stdlib.h>

#include "gameboard.h"
#include "player.h"


othello_board_t board;
int main(void) {
    int start = 1;
    int number_moves = 0;
    int invalid_moves = 0;
    int moves[SIZE][SIZE] = {0};
    do {
        //Player A goes first
        if(start++ % 2 == 0) {
            printf("It's Player A's Turn\n");
            if(valid_moves(&board,moves,PLAYER_A)){
	    }
        }

    }while(number_moves < SIZE*SIZE && invalid_moves < 0);

}
