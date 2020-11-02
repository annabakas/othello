#include "logic.h"
#include "player.h"
#include "gameboard.h"
#include "utility.h"
#include "computer.h"

#include <stdio.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//Make copy of board
void copy_board(othello_board_t *board, char tempBoard[SIZE][SIZE]) {
    for(int row = 0; row < SIZE; row++) {
        for(int col = 0; col < SIZE; col++) {
            tempBoard[row][col] = board -> board[row][col];
        }
    }
}
