#include "player.h"
#include "gameboard.h"

#include <stdio.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void prompt_move(int *r, int *c) {
    printf("Enter row [1-8] and column [1-8] separated by a single space (ex: 2 4): ");
    scanf("%d %d", r, c);
    fflush(stdin);
}

int valid_moves(othello_board_t *board, int moves[][SIZE], char player) {
    int row_count = 0;
    int col_count = 0;
    int r = 0;
    int c = 0;
    int x = 0;
    int y = 0;
    int number_moves = 0;

    char playerB = (player == PLAYER_A) ? PLAYER_B : PLAYER_A;
    //Initialize moves array to zero
    for(r = 0; r < SIZE; r++) {
        for(c = 0; c < SIZE; c++) {
            moves[r][c] = 0;
        }
    }

    for(r = 0; r < SIZE; r++) {
        for(c = 0; c < SIZE; c++) {
            if(board -> board[r][c] != EMPTY) {
                continue;
            }

            for(row_count = -1; row_count <= 1; row_count++) {
                for(col_count = -1; col_count <= 1; col_count++) {
                    if(r + row_count < 0 || r + row_count >= SIZE || c + col_count < 0 || c + col_count >= SIZE || (row_count == 0 && col_count == 0)) {
                        continue;
                    }

                    if(board -> board[r+row_count][c+col_count] == playerB) {
                        x = r + row_count;
                        y = c + col_count;

                        for(;;) {
                            x += row_count;
                            y += col_count;

                            if(x < 0 || x >= SIZE || y < 0 || y >= SIZE) {
                                break;
                            }

                            if(board -> board[x][y] == EMPTY) {
                                break;
                            }

                            if(board -> board[x][y] == player) {
                                moves[r][c] = 1;
                                number_moves++;
                                break;
                            }
                        }
                    }
                }
            }
        }
    }
}
