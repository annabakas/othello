#include "player.h"
#include "gameboard.h"
#include "logic.h"
#include "utility.h"
#include "computer.h"

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

//Display if player has to pass their turn
void pass_move(char *again) {
    fflush(stdin);
    printf("You have to pass. Please press enter");
    scanf("%c", again);
}

//Prompt user to enter if they want to play again or not
void play_again(char *again) {
    fflush(stdin);
    printf("\nDo you want to play again? (y/n): ");
    scanf(" %c", again);
}

//Print out possible moves for player to make at their turn
void print_possible_moves(int r, int c) {
    int x = r;
    int y = c;
    x++;
    y++;
    printf("%d %d\n", x, y);
}

//Initializes moves array to zero
void init_moves(int moves[][SIZE]) {
    int row, col;
    for(row = 0; row < SIZE; row++) {
        for(col = 0; col < SIZE; col++) {
            moves[row][col] = 0;
        }
    }

}

//Avoid outside of array and current square
//Return 1 if avoiding, 0 if not
int avoid(int r, int c, int row_count, int col_count) {
    if(r + row_count < 0 || r + row_count >= SIZE || c + col_count < 0 || c + col_count >= SIZE || (row_count == 0 && col_count == 0)) {
        return 1;
    }
    return 0;
}

//Returning opponent of current player
char set_opponent(char player) {
    if(player == PLAYER_A) {
        return PLAYER_B;
    }
    else {
        return PLAYER_A;
    }
}

//Finding which squares are valid moves for each player
//A valid move is one in which the current player's piece is adjacent
//to an opponent's piece.
//Returns total number of moves that are valid
int valid_moves(othello_board_t *board, int moves[][SIZE], char player) {
    int row_count = 0;
    int col_count = 0;
    int r = 0;
    int c = 0;
    int x = 0;
    int y = 0;
    int total_moves = 0;

    //Set which player is the opponent
    char other = set_opponent(player);

    init_moves(moves);

    //Valid move = a blank square and encloses at least one opponent square
    //between two player squares
    for(r = 0; r < SIZE; r++) {
        for(c = 0; c < SIZE; c++) {
            //If square is not empty, keep going
            if(board -> board[r][c] != EMPTY) {
                continue;
            }
            //Checking squares around blank square for opponent's piece
            for(row_count = -1; row_count <= 1; row_count++) {
                for(col_count = -1; col_count <= 1; col_count++) {
                    //Ignore outside the array or the current square
                    if(avoid(r,c,row_count,col_count) == 1) {
                        continue;
                    }
                    //Checking the square
                    //If other's piece is found then
                    //search for player's piece
                    if(board -> board[r+row_count][c+col_count] == other) {
                        x = r + row_count;
                        y = c + col_count;

                        //Looking for player piece
                        while(1) {
                            x += row_count;
                            y += col_count;

                            //Move outside the matrix? Give up
                            if(off_board(x, y) == 1) {
                                break;
                            }

                            //Encounter blank square? Give up
                            if(found_blank(board, x, y) == 1) {
                                break;
                            }


                            //If square has a player piece -> valid move
                            //Mark valid move as 1 in moves array
                            //Increment total_moves count
                            //Break to keep checking other squares
                            if(board -> board[x][y] == player) {
                                moves[r][c] = 1;
                                playable_squares(board, r, c);
                                //print_possible_moves(r,c);
                                total_moves++;
                                break;
                            }
                        }
                    }
                }
            }
        }
    }
    return total_moves;
}
