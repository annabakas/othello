#include <stdio.h>
#include <stdlib.h>

#include "gameboard.h"
#include "player.h"
int playerTurn = 1;
int moves[ROWS][COLS] = {0};
player_t first;

int main() {
    othello_new();
    if(playerTurn++ % 2) {
	    printf("Player W's Turn\n");
	    displayBoard();
    }
    else{
	    printf("Player B's Turn\n");
	    displayBoard();
    }
}
