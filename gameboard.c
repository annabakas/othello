#include "gameboard.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void othello_new(othello_board_t* board){
	for(int x = 0; x < ROWS; x++){
		for(int g = 0; g < COLS; g++){
			board -> board[x][g] = '*';
		}
	}
}

void print_othello(othello_board_t* board){
	for(int x = 0; x < ROWS; x++){
		for(int y = 0; y < COLS; y++){
			printf("%c", board->board[x][y]);
		}
		printf("\n");
	}
}

int main(){
	othello_board_t board;
	othello_new(&board);
	print_othello(&board);
}



