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
TEST(GameboardTests, Initialized) {
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
int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
