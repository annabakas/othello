#include <stdio.h>
#include <stdlib.h>

#include "gameboard.h"
#include "player.h"

int quit = 0;

int moves[SIZE][SIZE] = {0};
player_t first, second, other, current;
othello_board_t board;
int main(void) {
    othello_new(&board);

    init_first_player(&first);
    init_second_player(&second);

    current = first;
    other = second;
    while(quit == 0) {
        displayBoard(&board);
        printf("It's %s's turn\n", current.name);
        make_move(&current, &board);
        swap_players(&current, &other);
    }
}
