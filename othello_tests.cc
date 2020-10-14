/* test cases */

#include <gtest/gtest.h>

#include "gameboard.hh"
#include <stdio.h>

//Testing that board is not full at start
TEST(GameboardTests, isFull) {
    othello_new();
    ASSERT_EQ(board_full(), 0);
}

//Testing that board was initialized with four center pieces
TEST(GameboardTests, InitializedCenter) {
    othello_new();
    char pieceA[3] = "X";
    char pieceB[3] = "0";
    char player_A_init[3] = {board[3][3] -> color};
    char player_A_init2[3] = {board[4][4] -> color};
    char player_B_init[3] = {board[3][4] -> color};
    char player_B_init2[3] = {board[4][3] -> color};
    ASSERT_STREQ(pieceA,player_A_init);
    ASSERT_STREQ(pieceA,player_A_init);
    ASSERT_STREQ(pieceB,player_B_init);
    ASSERT_STREQ(pieceB,player_B_init2);
}

//Testing that non center pieces are blank
TEST(GameboardTests, InitializedBlanks) {
    char blank[3] = " ";
    int row, col;
    for(row = 0; row < 8; row++) {
        for(col = 0; col < 8; col++) {
            if((row != 3 && col != 3) && (row != 4 && col != 4)) {
                char piece[3] = {board[row][col] -> color};
                ASSERT_STREQ(blank, piece);
            }
            else if((row != 3 && col !=4) && (row != 4 && col != 3)) {
                char piece2[3] = {board[row][col] -> color};
                ASSERT_STREQ(blank, piece2);
            }
        }
    }
}
int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
