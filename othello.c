#include <stdio.h>
#include <stdlib.h>

#include "gameboard.h"
#include "player.h"
#include "logic.h"
#include "utility.h"

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

    welcome();

    do {
        playerA_Score = getScore(&board, player);
        playerB_Score = getScore(&board, other);
        display_score(playerA_Score, playerB_Score);

        if(start % 2 == 0) {
            display_current_player(player);
            if(valid_moves(&board,moves,player)) {
                displayBoard(&board);
                for(;;) {
                    prompt_move(&row, &col);

                    //Decrement row and column input to get index value
                    row = get_index(row);
                    col = get_index(col);

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
                        display_invalid_coords();
                    }
                }
            }
            else {
                if(++invalid_moves < 2) {
                    pass_move(&again);
                }
                else {
                    printf("Neither us us can go. Game Over.\n");
                }
            }
        }
        else {
            display_current_player(other);
            if(valid_moves(&board,moves,other)) {
                displayBoard(&board);
                for(;;) {
                    prompt_move(&row, &col);

                    //Decrement row and column input by one to get index value
                    row = get_index(row);
                    col = get_index(col);

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
                        display_invalid_coords();
                    }
                }
            }
            else {
                if(++invalid_moves < 2) {
                    pass_move(&again);
                }
                else {
                    printf("Neither us us can go. Game Over.\n");
                }
            }
        }
        start++; // Switching between player A and player B
    } while(quit(&board, invalid_moves) == 1);

    printf("\nCongrats Player %c, you won!\n",get_winner(playerA_Score, playerB_Score));
}
