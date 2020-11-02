#include "utility.h"
#include "logic.h"
#include "player.h"
#include "gameboard.h"
#include "computer.h"

#include <stdio.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//Display welcome message
void welcome() {
    printf("Welcome to Othello! Player A will go first. Playable squares are marked with an asterisk (*)\n");
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

//Return 1 if board is not full and invalid moves are less than 2
//Quit gameplay loop is quit() returns 0
int quit(othello_board_t *board, int invalid_moves) {
    if((board_full(board) != 1) && invalid_moves < 2) {
        return 1;
    }
    else {
        return 0;
    }
}

//Passes in row/column input by user and decrements it by 1 to get index value
//Returns decremented value
int get_index(int x) {
    x--;
    return x;
}

//Returns score of current player
//i.e. the number of pieces they have on the board currently
int getScore(othello_board_t *board, char player) {
    int score = 0;
    for(int row = 0; row < SIZE; row++) {
        for(int col = 0; col < SIZE; col++) {
            if(board -> board[row][col] == player) {
                score++;
            }
        }
    }

    return score;
}

//Displays current players' scores
void display_score(int playerA_Score, int playerB_Score) {
    printf("\nPlayer A's Score: %d\n", playerA_Score);
    printf("Player B's Score: %d\n\n", playerB_Score);
}


//Displays current player
void display_current_player(char player) {
    printf("Player %c, it's your turn!\n\n", player);
}


//Displays message when invalid coordinates are entered
void display_invalid_coords() {
    printf("Those coordinates are invalid. Check the board again for valid moves.\n");
}
