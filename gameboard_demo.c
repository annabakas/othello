#include <stdio.h>
#include <stdlib.h>

#include "gameboard.h"

int main() {
    othello_board_t board;
    othello_board_copy_t copy_board;
    othello_new(&board);
    othello_copy(&board, &copy_board);
    printf("\n");
    print_othello(&board);
}
