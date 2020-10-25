#include <stdio.h>
#include <stdlib.h>

#include "gameboard.h"
#include "player.h"
#include "logic.h"


othello_board_t board;
int main(void) {
    int start = 0;
    char again = 0;
    int total_moves = 0;
    int invalid_moves = 0;
    int row, col;
    char player = PLAYER_A;
    char other = PLAYER_B;
    int moves[SIZE][SIZE] = {0};
    int playerA_Score = 0;
    int playerB_Score = 0;
    
    //Initialize a new gameboard
    othello_new(&board);

    //Initial four pieces on the board
    total_moves = 4;

    printf("Welcome to Othello! Playable squares will be marked with a *\n");

    do {
        playerA_Score = getScore(&board, player);
        playerB_Score = getScore(&board, other);
        printf("\nPlayer A's Score: %d\n", playerA_Score);
        printf("Player B's Score: %d\n\n", playerB_Score);
        
        if(start % 2 == 0) {
            printf("It's Player %c's Turn\n", player);
            //printf("Possible Moves: \n");
            if(valid_moves(&board,moves,player)) {
                displayBoard(&board);
                for(;;) {
                    prompt_move(&row, &col);
                    row--;  //Decrement user input by one to get row/col index
                    col--;
                    
                    //If position entered is valid:
                    //Put move on board
                    //Clear playable moves from board
                    //Increment totals moves by one
                    if(is_valid_position(row,col) == 1 && moves[row][col]) {
                        make_move(&board, row, col, player);
                        clear_playable(&board);
                        total_moves++;
                        break;
                    }
                    else {
                        printf("Those coordinates are not valid. Please try again!\n");
                    }
                }
            }
            else {
                if(++invalid_moves < 2) {
                    fflush(stdin);
                    printf("You have to pass. Please press enter");
                    scanf("%c", &again);
                }
                else {
                    printf("Neither us us can go. Game Over.\n");
                }
            }
        }
        else {
            printf("It's Player %c's Turn\n", other);
            //printf("Possible Moves: \n");
            if(valid_moves(&board,moves,other)) {
                displayBoard(&board);
                for(;;) {
                    prompt_move(&row, &col);
                    row--;  //Decrement user input by one to get row/col index
                    col--;
                    
                    //If position entered is valid:
                    //Put move on board
                    //Clear playable moves from board
                    //Increment totals moves by one
                    if(is_valid_position(row,col) == 1 && moves[row][col]) {
                        make_move(&board, row, col, other);
                        clear_playable(&board);
                        total_moves++;
                        break;
                    }
                    else {
                        printf("Those coordinates are not valid. Please try again!\n");
                    }
                }
            }
            else {
                if(++invalid_moves < 2) {
                    fflush(stdin);
                    printf("You have to pass. Please press enter");
                    scanf("%c", &again);
                }
                else {
                    printf("Neither us us can go. Game Over.\n");
                }
            }
        }
        start++; // Switching between player A and player B
    } while(total_moves < SIZE*SIZE && invalid_moves<2);

    printf("\nCongrats Player %c, you won!\n",get_winner(playerA_Score, playerB_Score));
}
