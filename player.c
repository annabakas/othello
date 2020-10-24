#include "player.h"
#include "gameboard.h"

#include <stdio.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//Prompts player to enter coordinates for location they wish to place their piece
void prompt_move(int *r, int *c) {
    printf("\nEnter row [1-8] and column [1-8] separated by a single space (ex: 2 4): ");
    scanf("%d %d", r, c);
    fflush(stdin);
}

void print_possible_moves(int r, int c){
	int x = r;
	int y = c;
	x++;
	y++;
	printf("%d, %d\n", x, y);
}
//Finding which squares are valid moves for each player
//Valid moves are stored in moves[][]
//Returns number of moves that are valid
int valid_moves(othello_board_t *board, int moves[][SIZE], char player) {
    int row_count = 0;
    int col_count = 0;
    int r = 0;
    int c = 0;
    int x = 0;
    int y = 0;
    int number_moves = 0;

    //Set which player is the opponent
    char other = (player == PLAYER_A) ? PLAYER_B : PLAYER_A;

    //Initialize moves array to zero
    for(r = 0; r < SIZE; r++) {
        for(c = 0; c < SIZE; c++) {
            moves[r][c] = 0;
        }
    }

    //Valid move = a blank square and encloses at least one opponent square
    //between two player squares
    for(r = 0; r < SIZE; r++) {
        for(c = 0; c < SIZE; c++) {
            if(board -> board[r][c] != EMPTY) {
                continue;
            }
            //Checking squares around blank square for opponent's piece
            for(row_count = -1; row_count <= 1; row_count++) {
                for(col_count = -1; col_count <= 1; col_count++) {
                    //Ignore outside the array or the current square
                    if(r + row_count < 0 || r + row_count >= SIZE || c + col_count < 0 || c + col_count >= SIZE || (row_count == 0 && col_count == 0)) {
                        continue;
                    }
                    //Check square
                    if(board -> board[r+row_count][c+col_count] == other) {
                        x = r + row_count;
                        y = c + col_count;

                        for(;;) {
                            x += row_count;
                            y += col_count;

                            if(x < 0 || x >= SIZE || y < 0 || y >= SIZE) {
                                break;
                            }

                            if(board -> board[x][y] == EMPTY) {
                                break;
                            }


                            //If square has a player piece -> valid move
                            if(board -> board[x][y] == player) {
                                moves[r][c] = 1;
				print_possible_moves(r,c);
                                number_moves++;
                                break;
                            }
                        }
                    }
                }
            }
        }
    }

    return number_moves;
}
