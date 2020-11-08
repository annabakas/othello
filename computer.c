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

int best(othello_board_t *board, int moves[][SIZE], char player, int search) {
    char opponent = set_opponent(player);
    char origTurn = player;
    int score = 0;
    int newScore = 0;

    othello_board_t tempBoard;

    for(int r = 0; r < SIZE; r++) {
        for(int c = 0; c < SIZE; c++) {
            if(!moves[r][c]) {
                continue;
            }

            copy_board(board, &tempBoard);

            make_move(&tempBoard, r, c, player);

            newScore = getScore(&tempBoard, player);
            //printf("new score: %d\n", newScore);
            if(score < newScore) {
                score = newScore;
                //printf("Score: %d\n", score);
            }
        }
    }
    return score;
}

void assign_best(int new_score, int score, int best_row, int row, int best_col, int col) {
    score = new_score;
    best_row = row;
    best_col = col;
}

void best_coord(int best_row, int best_col, int r, int c) {
    best_row = r;
    best_col = c;
}

int set_high(int tempScore, int max){
	if(tempScore > max){
		return 0;
	}
	else{
		return 1;
	}
}

void decision(othello_board_t *board, int moves[][SIZE], char player) {
    //Set opponent
    char opponent = set_opponent(player);
    //Temporary board
    othello_board_t tempBoard;
    //Temporary valid moves array
    int tempMoves[SIZE][SIZE];
    int max = 0;

    int newScore = 0;
    int score = 100;
    int best_row = 0;
    int best_col = 0;

    //Go through all valid moves
    for(int r = 0; r < SIZE; r++) {
        for(int c = 0; c < SIZE; c++) {
            if(!moves[r][c]) {
                continue;
            }
            //Copy board into tempBoard
            copy_board(board, &tempBoard);

            //Make valid move onto temporary board
            make_move(&tempBoard, r, c, player);

            //Score for each valid move
            int tempScore = getScore(&tempBoard, player);

            //Use row and column that produces highest score
            if(set_high(tempScore, max) == 0) {
                max = tempScore;
                best_row = r;
                best_col = c;
            }

            //printf("Temporary Move #%d\n", r);

            //Checking temporary board state
            //displayBoard(&tempBoard);

            //Find valid moves for opponent after current player makes move

            /*valid_moves(&tempBoard, tempMoves, opponent);


            //Find score for opponent's best move
                int val = best(&tempBoard, tempMoves, opponent, 1);
                //printf("%d\n", val);

            //printf("row: %d, col: %d\n", r, c);
                if(val < score) {
                    //assign_best(val, score, best_row, r, best_col, c);
                    score = val; //New lowest opponent move
                    best_row = r;
                    best_col = c;
                    printf("best row: %d\n best col: %d\n", best_row, best_col);
                }*/
        }
    }
    make_move(board, best_row, best_col, player);
}
