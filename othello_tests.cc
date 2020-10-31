/* test cases */

#include <gtest/gtest.h>

#include "gameboard.hh"
#include "player.hh"
#include "logic.hh"
#include "utility.hh"
#include <stdio.h>

//Testing that not full board returns 0
TEST(GameboardTests, NotFull) {
    othello_board_t board;
    othello_new(&board);
    ASSERT_EQ(0, board_full(&board));
}

//Testing that if board is full, return 1
TEST(GameboardTests, IsFull) {
    othello_board_t board;
    othello_new(&board);
    for(int row = 0; row < SIZE; row++) {
        for(int col = 0; col < SIZE; col++) {
            board.board[row][col] = PLAYER_A;
        }
    }

    ASSERT_EQ(1, board_full(&board));
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

//Testing that valid coordinate returns 1
TEST(GameboardTests, ValidPosition) {
    ASSERT_EQ(1, is_valid_position(0,1));
}

//Testing that invalid coordinate returns 0
TEST(GameboardTests, InvalidPosition) {
    ASSERT_EQ(0, is_valid_position(10,2));
}

//Testing that prompted move is stored correctly
TEST(PlayerTests, PromptMove) {
    int row = 0;
    int col = 0;
    printf("Use 4 4 for this test\n");
    prompt_move(&row, &col);
    ASSERT_EQ(4, row);
    ASSERT_EQ(4, col);
}

//Testing that opponent of current player is set correctly
TEST(PlayerTests, SetOpponent) {
    ASSERT_EQ(PLAYER_B, set_opponent(PLAYER_A));
    ASSERT_EQ(PLAYER_A, set_opponent(PLAYER_B));
}

//Testing within the matrix
//Return 0 if within the matrix
TEST(PlayerTests, NotAvoid) {
    int r = 0;
    int c = 0;
    int col_count = 1;
    int row_count = 2;
    ASSERT_EQ(0, avoid(r, c, row_count, col_count));
}

//Testing outside the matrix
//Return 1 if outside the matrix
TEST(PlayerTests, Avoid) {
    int r = 10;
    int c = 10;
    int row_count = 12;
    int col_count = 12;
    ASSERT_EQ(1, avoid(r, c, row_count, col_count));
}

//Testing that correct winner is returned
TEST(LogicTests, Winner) {
    int play1 = 10;
    int play2 = 20;
    ASSERT_EQ(PLAYER_B, get_winner(play1, play2));
}

//Testing that off_board identifies if coordinates are off the board
TEST(LogicTests, OffBoard) {
    int row = 10;
    int col = 13;
    ASSERT_EQ(1, off_board(row, col));
}

//Testing that off_board identifies if coordinates are on the board
TEST(LogicTests, OnBoard) {
    int row = 3;
    int col = 4;
    ASSERT_EQ(0, off_board(row, col));
}

//Testing that found_blank identifies if square is blank
TEST(LogicTests, FoundBlank) {
    int row = 6;
    int col = 6;
    othello_board_t board;
    othello_new(&board);
    ASSERT_EQ(1, found_blank(&board,row,col));
}

//Testing that found_blank identifies if square is not blank
TEST(LogicTests, NotBlank) {
    int row = 4;
    int col = 4;
    othello_board_t board;
    othello_new(&board);
    ASSERT_EQ(0, found_blank(&board, row, col));
}

//Testing that game shouldn't quit when board isn't full AND invalid moves < 2
TEST(UtilityTests, NoQuit) {
    othello_board_t board;
    int invalid_moves = 0;
    othello_new(&board);
    ASSERT_EQ(1, quit(&board, invalid_moves));
}

//Testing that game should quit when board isn't full AND invalid moves > 2
TEST(UtilityTests, DoQuit) {
    othello_board_t board;
    int invalid_moves = 6;
    othello_new(&board);
    ASSERT_EQ(0, quit(&board, invalid_moves));
}

//Testing that row and column input by user is decremented by one to get row/col index
TEST(UtilityTests, Decrement) {
    int row = 9;
    int col = 7;
    ASSERT_EQ(8, get_index(row));
    ASSERT_EQ(6, get_index(col));
}

//Testing that getScore returns correct score
//In this case: for initial set up
TEST(UtilityTests, InitialScore) {
    othello_board_t board;
    othello_new(&board);
    ASSERT_EQ(2, getScore(&board, PLAYER_A));
    ASSERT_EQ(2, getScore(&board, PLAYER_B));
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
