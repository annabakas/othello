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
    /*for(int row = 0; row < SIZE; row++) {
        for(int col = 0; col < SIZE; col++) {
            tempBoard -> tempBoard[row][col] = board -> board[row][col];
        }
    }*/

    tempBoard = board;
}

//Returns current player's score minus opponent's score
int heuristic(othello_board_t *board, char player) {
    char opponent = set_opponent(player);
    int playerScore = getScore(board, player);
    int opponentScore = getScore(board, opponent);
    return (playerScore - opponentScore);
}

void decision(othello_board_t *board, int moves[][SIZE], char player) {
    int numMoves;
    char opponent = set_opponent(player);
    othello_board_t tempBoard;
    int tempMoves[SIZE][SIZE];
    int row, col;
    int moveX[60], moveY[60];


    numMoves = valid_moves(&tempBoard, tempMoves, player);

    if(numMoves == 0) {
        row = -1;
        col = -1;
    }
    else {
        int bestMoveVal = -99999;
        int bestX = moveX[60], bestY = moveY[0];

        for(int i = 0; i < numMoves; i++) {
            copy_board(board, &tempBoard);
            make_move(tempBoard, row, col, player);

            int val = minimaxVal(&tempBoard, player, opponent, 1);

            if(val > bestMoveVal) {
                bestMoveVal = val;
                bestX = moveX[i];
                bestY = moveY[i];
            }
        }
        x = bestX;
        y = bestY;
    }
}


