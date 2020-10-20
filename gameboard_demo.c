#include <stdio.h>
#include <stdlib.h>

#include "gameboard.h"
#include "player.h"

int quit = 0;

int moves[ROWS][COLS] = {0};
player_t first, second, other, current;
othello_board_t *board[ROWS][COLS];

int main(void) {
    othello_new();

    init_first_player(&first);
    init_second_player(&second);

    current = first;
    other = second;
    while(quit == 0) {
        displayBoard();
        printf("It's %s's turn\n", current.name);
        make_move(&current, &board);
        swap_players(&current, &other);
    }
}
