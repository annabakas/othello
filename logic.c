#include "logic.h"
#include "player.h"
#include "gameboard.h"

#include <stdio.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void make_move(othello_board_t *board, int r, int c, char player) {
    int row_count = 0;
    int col_count = 0;
    int x = 0;
    int y = 0;

    char other = (player == PLAYER_A) ? PLAYER_B : PLAYER_A;

    //Place player's piece on the board
    board -> board[r][c] = player;

    //Checking squares around blank square for opponent's piece
    for(row_count = -1; row_count <= 1; row_count++) {
        for(col_count = -1; col_count <= 1; col_count++) {
            //Ignore outside the array or the current square
            if(avoid(r,c,row_count,col_count) == 1) {
                continue;
            }

            //If we find the opponent's piece, then search for player's piece
            if(board -> board[r + row_count][c + col_count] == other) {
                x = r + row_count; //Moving to where opponent's piece is
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

                    //If square has a player piece -> go back
                    //Change all opponent counters to player
                    if(board -> board[x][y] == player) {
                        while(board -> board[x-=row_count][y-=col_count] == other) {
                            board -> board[x][y] = player;
                        }
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

