#include "logic.h"
#include "player.h"
#include "gameboard.h"
#include "utility.h"
#include "computer.h"

#include <stdio.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//Make copy of board
void copy_board(othello_board_t *board, othello_board_t *tempBoard) {
    for(int row = 0; row < SIZE; row++) {
        for(int col = 0; col < SIZE; col++) {
            tempBoard -> board[row][col] = board -> board[row][col];
        }
    }
}

//Returns current player's score minus opponent's score
int heuristic(othello_board_t *board, char player) {
    char opponent = set_opponent(player);
    int playerScore = getScore(board, player);
    int opponentScore = getScore(board, opponent);
    return (playerScore - opponentScore);
}

int best(othello_board_t *board, int moves[][SIZE], char player) {
}

void decision(othello_board_t *board, int moves[][SIZE], char player) {
    //Set opponent
    char opponent = set_opponent(player);
    //Temporary board
    othello_board_t tempBoard;
    //Temporary valid moves array
    int tempMoves[SIZE][SIZE];

    //Go through all valid moves
    for(int r = 0; r < SIZE; r++) {
        for(int c = 0; c < SIZE; c++) {
            if(moves[r][c] == 0) {
                continue;
            }
            //Copy board into tempBoard
            copy_board(board, &tempBoard);
            //Make valid move onto temporary board
            make_move(&tempBoard, r, c, player);

            //Find score for opponent's best move
            int val = best(&tempBoard, tempMoves, opponent);
        }
    }
}


