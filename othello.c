#include <stdio.h>
#include <stdlib.h>

#include "gameboard.h"
#include "player.h"
#include "logic.h"


othello_board_t board;
int main(void) {
    int start = 0;
    int number_moves = 0;
    int invalid_moves = 0;
    int row, col;
    char again = 0;
    char player = PLAYER_A;
    char other = PLAYER_B;
    int moves[SIZE][SIZE] = {0};

    othello_new(&board);

    //Initial four pieces on the board
    number_moves = 4;

    while(number_moves < SIZE*SIZE && invalid_moves<2) {
        //Player A goes first
        printf("It's Player %c's Turn\n", player);

        displayBoard(&board);

        printf("Possible Moves: \n");


        if(valid_moves(&board,moves,player)) {
            for(;;) {
                prompt_move(&row, &col);
                row--;
                col--;

                if(is_valid_position(row,col) == 1 && moves[row][col]) {
                    make_move(&board, row, col, player);
                    number_moves++;
                    //printf("%d\n", number_moves);
                    displayBoard(&board);
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
        player = switch_players(player, other);
    }
}
