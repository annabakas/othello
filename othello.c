#include <stdio.h>
#include <stdlib.h>

#include "gameboard.h"
#include "player.h"
#include "logic.h"


othello_board_t board;
int main(void) {
    int start = 1;
    int number_moves = 0;
    int invalid_moves = 0;
    int row, col;
    char again = 0;
    int moves[SIZE][SIZE] = {0};

    othello_new(&board);
    number_moves = 4;
    do {
        //Player A goes first
        if(start++ % 2) {
            printf("It's Player A's Turn\n");
            displayBoard(&board);
            if(valid_moves(&board,moves,PLAYER_A)) {
                for(;;) {
                    prompt_move(&row, &col);
                    row--;
                    col--;

                    if(is_valid_position(row,col) == 1 && moves[row][col]) {
                        make_move(&board, row, col, PLAYER_A);
                        number_moves++;
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
        }

    } while(number_moves < SIZE*SIZE && invalid_moves < 0);
}
