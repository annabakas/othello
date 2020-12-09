#include "logic.h"
#include "player.h"
#include "gameboard.h"
#include "utility.h"
#include "computer.h"

#include <stdio.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

//Returns current player's score minus opponent's score
//The greater the number, the more attractive the move is
int heuristic(othello_board_t *board, char player) {
    char opponent = set_opponent(player);
    int playerScore = getScore(board, player);
    int opponentScore = getScore(board, opponent);
    return (playerScore - opponentScore);
}

//Recursive function that returns the best move value
//Original turn parameter determines if it's a minimizing or maximizing move
//Original turn parameter is the player who started the move
//Search parameter controls when we stop searching in the tree
int minimaxVal(othello_board_t *tempBoard, char origTurn, char currentTurn, int search) {
    //Lookahead equal to 6 but can be changed
    if((search == 6) || gameOver(tempBoard)) {
        return heuristic(tempBoard, origTurn);
    }

    int tempMoves[SIZE][SIZE];
    int numMoves = valid_moves(tempBoard, tempMoves, currentTurn);
    int val = 0;
    int bestMoveScore = 0; //Result
    char opponent = set_opponent(currentTurn);

    //No valid moves? Skip to next player
    if(numMoves == 0) {
        return minimaxVal(tempBoard, origTurn, opponent, search + 1);
    }
    else {
        bestMoveScore = -99999; //To find max
        if(origTurn != currentTurn) {
            bestMoveScore = 99999; //To find min
        }

        //Loop through all valid moves
        for(int r = 0; r < SIZE; r++) {
            for(int c = 0; c < SIZE; c++) {
                //Ignore invalid moves
                if(tempMoves[r][c] == 0) {
                    continue;
                }

                othello_board_t newTempBoard; //new temporary board
                copy_board(tempBoard, &newTempBoard); //copy state of tempBoard into newTempBoard
                make_move(&newTempBoard, r, c, currentTurn); //make valid move on newTempBoard

                //Recursive call where we increment search by 1
                val = minimaxVal(&newTempBoard, origTurn, opponent, search + 1);

                if(origTurn == currentTurn) {
                    //Remember max if it's the original player's turn
                    //Maximizer works to get the highest score
                    if(val > bestMoveScore) {
                        bestMoveScore = val;
                    }
                }
                else {
                    //Remember min if it's the opponent's turn
                    //Opponent wants to minimize current player's val
                    if(val < bestMoveScore) {
                        bestMoveScore = val;
                    }
                }
            }
        }
        return bestMoveScore;
    }
    return -1;
}

//Loops through computer's valid moves
//Call to minimaxVal with search of 1
//Stores best x and y coordinate
//Makes best move on the board that leads to the most points
void minimax(othello_board_t *board, int moves[][SIZE], char currentTurn) {
    char opponent = set_opponent(currentTurn);
    int bestMoveScore = -999999;
    int bestR = 0;
    int bestC = 0;
    int val = 0;

    //Create temporary board
    othello_board_t tempBoard;

    for(int r = 0; r < SIZE; r++) {
        for(int c = 0; c < SIZE; c++) {
            //Ignore invalid moves
            if(moves[r][c] == 0) {
                continue;
            }

            copy_board(board, &tempBoard); //Copy current state of board into tempBoard
            make_move(&tempBoard, r, c, currentTurn); //make each valid move on tempBoard

            //Call to minimaxVal
            //Val stores the best move score from minimaxVal
            val = minimaxVal(&tempBoard, currentTurn, opponent, 1);

            //Val > current bestMoveScore
            //Set val to bestMoveScore
            //Store best coordinates in bestR and bestC
            if(val > bestMoveScore) {
                bestMoveScore = val;
                bestR = r;
                bestC = c;
            }
        }
    }
    //Make best move on board
    make_move(board, bestR, bestC, currentTurn);
}
