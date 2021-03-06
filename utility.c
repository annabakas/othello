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
    printf("Welcome to Othello! Playable squares are marked with an asterisk (*)\n");
}

//Takes in user's gameplay choice and checks if it's a valid one
//Return 1 if invalid, 0 if valid
int valid_choice(char letter) {
    if(letter == 'A' || letter == 'B' || letter == 'C') {
        return 0;
    }
    else {
        return 1;
    }
}

//Prompt user to pick what type of game they want to play
//Check if user's choice is a valid one
//If valid, return choice
//If invalid, prompt user again to enter valid choice
char game_choice() {
    char choice;
    char lastChar;
    printf("\nTime to Pick What Kind of Game You Want to Play!\n");
    do {
        printf("\nA: Human vs. Human\n");
        printf("B: Human vs. Computer\n");
        printf("C: Computer vs. Computer\n");
        printf("\nChoice: ");
        fflush(stdin);
        lastChar = getchar();
        getchar();
        if(lastChar == '\n') {
            break;
        }
        choice = lastChar;
        if(valid_choice(choice) == 0) {
            break;
        }
        printf("\nInvalid Choice. Choose A, B, or C.\n");
        fflush(stdin);
    } while(1);
    return choice;
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

//Return 1 if player A won
//Return 0 if player B won
int who_won(int playerA_Score, int playerB_Score) {
    if(get_winner(playerA_Score, playerB_Score) == PLAYER_A) {
        return 1;
    }
    else {
        return 0;
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

//Game over when no player has valid moves left
int gameOver(othello_board_t *tempBoard) {
    int moves1[SIZE][SIZE] = {0};
    int moves2[SIZE][SIZE] = {0};
    int play1Moves = valid_moves(tempBoard, moves1, PLAYER_A);
    int play2Moves = valid_moves(tempBoard, moves2, PLAYER_B);

    if((play1Moves == 0) && (play2Moves == 0)) {
        return 0;
    }
    else {
        return 1;
    }
}
