#include "logic.h"
#include "player.h"
#include "gameboard.h"

#include <stdio.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int off_board(int x, int y) {
    if(x < 0 || x >= SIZE || y < 0 || y >= SIZE) {
        return 1;
    }
    else {
        return 0;
    }
}

int found_blank(othello_board_t *board, int x, int y) {
    if(board -> board[x][y] == EMPTY) {
        return 1;
    }
    else {
        return 0;
    }
}

void flip_pieces(othello_board_t *board, int x, int y, int row_count, int col_count, char other, char player) {
    while(board -> board[x-=row_count][y-=col_count] == other) {
        board -> board[x][y] = player;
    }
}

void place_piece(othello_board_t *board, int r, int c, char player){
	board -> board[r][c] = player;
}

void make_move(othello_board_t *board, int r, int c, char player) {
    int row_count = 0;
    int col_count = 0;
    int x = 0;
    int y = 0;

    //Identifying opponent
    char other = set_opponent(player);

    //Place player's piece on the board
    place_piece(board, r, c, player);

    //Checking squares around player's square for opponent's piece
    for(row_count = -1; row_count < 2; row_count++) {
        for(col_count = -1; col_count < 2; col_count++) {
            //Ignore outside the array or the current square
            if(avoid(r,c,row_count,col_count) == 1) {
                continue;
            }

            //If opponent's piece is found, then search in same
            //direction for player's piece so we know which pieces
            //need to be flipped
            if(board -> board[r + row_count][c + col_count] == other) {
                x = r + row_count;
                y = c + col_count;

                for(;;) {
                    x += row_count;
                    y += col_count;

                    //Move off the board? Break
                    if(off_board(x,y) == 1) {
                        break;
                    }
                    //Blank square? Break
                    if(found_blank(board, x, y) == 1) {
                        break;
                    }

                    //If square has a player piece -> backtrack to
                    //change all opponent counters to player's counter
                    if(board -> board[x][y] == player) {
                        flip_pieces(board, x, y, row_count, col_count, other, player);
                        break;
                    }
                }
            }
        }
    }
}

//Returning player who has the highest score i.e. the winner
char get_winner(int playerA_Score, int playerB_Score) {
    if(playerA_Score > playerB_Score) {
        return PLAYER_A;
    }
    else {
        return PLAYER_B;
    }
}
