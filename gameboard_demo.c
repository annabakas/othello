#include <stdio.h>
#include <stdlib.h>

#include "gameboard.h"
othello_board_t* othello[8][8];
int main() {
    othello_new();
    displayBoard();
    printf("%d\n",board_full());
    copyBoard();
}
