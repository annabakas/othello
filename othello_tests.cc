/* test cases */

#include <gtest/gtest.h>

#include "gameboard.hh"
#include <stdio.h>

TEST(GameboardTests, IsFull) {
    othello_board_t board;
    othello_new(&board);
    ASSERT_EQ(board_full(&board), 0);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
