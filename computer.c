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
            printf("new score: %d\n", newScore);
            if(score < newScore) {
                score = newScore;
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

void decision(othello_board_t *board, int moves[][SIZE], char player) {
    //Set opponent
    char opponent = set_opponent(player);
    //Temporary board
    othello_board_t tempBoard;
    //Temporary valid moves array
    int tempMoves[SIZE][SIZE];

    int newScore = 0;
    int score = 100;
    int best_row = 0;
    int best_col = 0;

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

            valid_moves(&tempBoard, tempMoves, opponent);
            //print_possible_moves(r,c);

            //Find score for opponent's best move
            int val = best(&tempBoard, tempMoves, opponent, 1);
            printf("%d\n", val);
            //printf("row: %d, col: %d\n", r, c);
            if(val < score) {
                //assign_best(val, score, best_row, r, best_col, c);
                score = val;
                best_row = r;
                best_col = c;
                printf("best row: %d\n best col: %d\n", best_row, best_col);
            }
        }
    }
    //printf("%d\n", best_row);
    //printf("%d\n", best_col);

    make_move(board, best_row, best_col, player);
}
int rand(void) {}
void randomPick(othello_board_t *board, int moves[][SIZE], char player, int numMoves) {
    time_t t;
    srand((unsigned)time(&t));
    
    int validRows[SIZE] = {0};
    int validCols[SIZE] = {0};
    int randomRow = 0;
    int randomCol = 0;
    int randomIndex = 0;
    //int r = moves[rand() % SIZE][rand() % SIZE];

    for(int row = 0; row < SIZE; row++) {
        for(int col = 0; col < SIZE; col++) {
            if(moves[row][col] == 1) {
                //printf("%d %d\n", row, col);
                validRows[row] = row;
                validCols[col] = col;
                
		printf("rows: %d ", validRows[row]);
                printf("cols: %d\n", validCols[col]);
            }
        }
    }

    randomIndex = rand() % SIZE;
    printf("Random Row: %d\n", validRows[randomIndex]);
}


