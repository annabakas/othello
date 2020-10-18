#include <stdio.h>
#include <stdlib.h>

#include "gameboard.h"
#include "player.h"

int main() {
    player_t first;
    othello_new();
    displayBoard();
    //printf("%d\n",board_full());
    copyBoard();
    //printf("%d\n",compareBoards());
    init_first_player(&first);
}
