#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#include "gameboard.h"
#include "player.h"
#include "logic.h"
#include "utility.h"
#include "computer.h"

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
    char chooseGame;
    time_t endwait;
    time_t startTime = time(NULL);
    time_t duration = 30;
    int gamesWon_A = 0;
    int gamesWon_B = 0;

    endwait = startTime + duration;

    //Initialize a new gameboard
    othello_new(&board);

    //Initial four pieces on the board
    total_moves = 4;

    //Display welcome message
    welcome();

    //Prompt user to choose gameplay
    //Store choice in chooseGame
    chooseGame = game_choice();

    //Use chooseGame value to pick gameplay with if statements
    if(chooseGame == 'A') {
        do {
            othello_new(&board);
            total_moves = 4;
            printf("\nWelcome to Human vs. Human Othello! Player A will go first.\n");
            do {
                playerA_Score = getScore(&board, player);
                playerB_Score = getScore(&board, other);
                printf("\nPlayer A's Score: %d\n", playerA_Score);
                printf("Player B's Score: %d\n\n", playerB_Score);

                if(start % 2 == 0) {
                    printf("It's Player %c's Turn\n", player);
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
            if(who_won(playerA_Score, playerB_Score) == 1) {
                gamesWon_A += 1;
            }
            else {
                gamesWon_B += 1;
            }
            fflush(stdin);
            printf("Do you want to play again? (y/n): ");
            scanf(" %c", &again);
        } while(again == 'y');
        printf("\nPlayer A Won %d Games\n", gamesWon_A);
        printf("Player B Won %d Games\n", gamesWon_B);
    }
    else if(chooseGame == 'B') {
        printf("\nWelcome to Human vs. Computer Othello! The Human player will go first.\n");
        do {
            playerA_Score = getScore(&board, player);
            playerB_Score = getScore(&board, other);
            display_score(playerA_Score, playerB_Score);

            if(start % 2 == 0) {
                //while(startTime < endwait) {
                //start = time(NULL);
                display_current_player(player);
                if(valid_moves(&board,moves,player)) {
                    displayBoard(&board);
                    while(1) {
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
                // }
                //printf("End time is %s\n", ctime(&endwait));
            }
            else {
                display_current_player(other);
                if(valid_moves(&board,moves,other)) {
                    displayBoard(&board);
                    invalid_moves = 0;
                    minimax(&board, moves, other); //Computer play
                    clear_playable(&board); //Clear asterisks indicating playable moves on the board
                    total_moves++;
                }
                else {
                    if(++invalid_moves < 2) {
                        printf("You have to pass.\n");
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
    else {
        printf("\nWelcome to Computer vs. Computer Othello!\n");
        do {
            playerA_Score = getScore(&board, player);
            playerB_Score = getScore(&board, other);
            display_score(playerA_Score, playerB_Score);

            if(start % 2 == 0) {
                display_current_player(player);
                if(valid_moves(&board,moves,player)) {
                    displayBoard(&board);
                    invalid_moves = 0;
                    minimax(&board, moves, player); //Computer play
                    clear_playable(&board); //Clear asterisks indicating playable moves on the board
                    total_moves++;
                }
                else {
                    if(++invalid_moves < 2) {
                        printf("You have to pass.\n");
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
                    invalid_moves = 0;
                    minimax(&board, moves, other); //Computer play
                    clear_playable(&board); //Clear asterisks indicating playable moves on the board
                    total_moves++;
                }
                else {
                    if(++invalid_moves < 2) {
                        printf("You have to pass.\n");
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
}
