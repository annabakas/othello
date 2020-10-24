/* test cases */

#include <gtest/gtest.h>

#include "gameboard.hh"
#include "player.hh"
#include "logic.hh"
#include <stdio.h>

//Testing that board is not full at start
TEST(GameboardTests, isFull) {
    othello_board_t board;
    othello_new(&board);
    ASSERT_EQ(board_full(&board), 0);
}

//Testing that board was initialized with four center pieces
TEST(GameboardTests, InitializedCenter) {
    othello_board_t board;
    othello_new(&board);
    char pieceA[3] = "A";
    char pieceB[3] = "B";
    char player_A_init[3] = {board.board[3][3]};
    char player_A_init2[3] = {board. board[4][4]};
    char player_B_init[3] = {board.board[3][4]};
    char player_B_init2[3] = {board.board[4][3]};
    ASSERT_STREQ(pieceA,player_A_init);
    ASSERT_STREQ(pieceA,player_A_init2);
    ASSERT_STREQ(pieceB,player_B_init);
    ASSERT_STREQ(pieceB,player_B_init2);
}

//Testing that non center pieces are blank
TEST(GameboardTests, InitializedBlanks) {
    char blank[3] = " ";
    int row, col;
    othello_board_t board;
    othello_new(&board);
    for(row = 0; row < 8; row++) {
        for(col = 0; col < 8; col++) {
            if((row != 3 && col != 3) && (row != 4 && col != 4)) {
                char piece[3] = {board.board[row][col]};
                ASSERT_STREQ(blank, piece);
            }
            else if((row != 3 && col !=4) && (row != 4 && col != 3)) {
                char piece2[3] = {board.board[row][col]};
                ASSERT_STREQ(blank, piece2);
            }
        }
    }
}

//Testing that position entered is valid
TEST(GameboardTests, ValidPosition) {
    ASSERT_EQ(0, is_valid_position(10,2));
    ASSERT_EQ(1, is_valid_position(0,1));
}

TEST(PlayerTests, PromptMove) {
    int row = 0;
    int col = 0;
    printf("Use 4 4 for this test\n");
    prompt_move(&row, &col);
    ASSERT_EQ(4, row);
    ASSERT_EQ(4, col);
}

TEST(LogicTests, Switch) {
    char playerA = 'A';
    char playerB = 'B';
    ASSERT_EQ(playerB, switch_players(playerA, playerB));
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

