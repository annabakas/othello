/* test cases */

#include <gtest/gtest.h>

#include "gameboard.hh"
#include "player.hh"
#include "logic.hh"
#include "utility.hh"
#include "computer.hh"

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

//Testing that board was successfully copied into temporary board
TEST(GameboardTests, Copied) {
    othello_board_t board;
    othello_new(&board);

    othello_board_t tempBoard;
    copy_board(&board, &tempBoard);

    char pieceA[3] = "A";
    char pieceB[3] = "B";
    char player_A_init[3] = {tempBoard.board[3][3]};
    char player_A_init2[3] = {tempBoard.board[4][4]};
    char player_B_init[3] = {tempBoard.board[3][4]};
    char player_B_init2[3] = {tempBoard.board[4][3]};
    ASSERT_STREQ(pieceA,player_A_init);
    ASSERT_STREQ(pieceA,player_A_init2);
    ASSERT_STREQ(pieceB,player_B_init);
    ASSERT_STREQ(pieceB,player_B_init2);
}

//Testing that playable squares are marked correctly
TEST(GameboardTests, MarkPlayable) {
    othello_board_t board;
    othello_new(&board);
    char play[3] = "*";

    playable_squares(&board, 0, 0);
    playable_squares(&board, 7, 7);
    playable_squares(&board, 8, 2);

    for(int r = 0; r < SIZE; r++) {
        for(int c = 0; c < SIZE; c++) {
            if((r == 0 && c == 0) || (r == 7 && c == 7) || (r == 8 && c == 2)) {
                char piece[3] = {board.board[r][c]};
                ASSERT_STREQ(play, piece);
            }
        }
    }
}

//Testing that playable squares are cleared from board
TEST(GameboardTests, ClearPlayable) {
    othello_board_t board;
    othello_new(&board);
    board.board[4][7] = PLAYABLE;
    board.board[1][1] = PLAYABLE;
    board.board[0][7] = PLAYABLE;
    char blank[3] = " ";

    clear_playable(&board);

    for(int r = 0; r < SIZE; r++) {
        for(int c = 0; c < SIZE; c++) {
            if((r == 4 && c == 7) || (r == 1 && c == 1) || (r == 0 && c == 7)) {
                char piece[3] = {board.board[r][c]};
                ASSERT_STREQ(blank, piece);
            }
        }
    }
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

//Testing that pass move/pressing enter is stored correctly
//ASCII code of Enter Key is 10 in decimal
TEST(PlayerTests, PassMove) {
    char again = 0;
    pass_move(&again);
    printf("\n");
    ASSERT_EQ(10, again);
}

//Testing that play again (y) is stored correctly
//ASCII code of 'y' is 121
TEST(PlayerTests, PlayAgain) {
    char again = 0;
    printf("\nAnswer y for this test\n");
    play_again(&again);
    ASSERT_EQ(121, again);
}

//Testing that not playing again (n) is stored correctly
//ASCII code of 'n' is 110
TEST(PlayerTests, NoPlayAgain) {
    char again = 0;
    printf("\nAnswer n for this test\n");
    play_again(&again);
    ASSERT_EQ(110, again);
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

//Testing that moves array was initialized with zeros
TEST(PlayerTests, InitMoves) {
    int moves[SIZE][SIZE] = {0};
    init_moves(moves);
    for(int r = 0; r < SIZE; r++) {
        for(int c = 0; c < SIZE; c++) {
            ASSERT_EQ(0, moves[r][c]);
        }
    }
}

//Testing that correct number of valid moves are returned
TEST(PlayerTests, NumberOfValidMoves) {
    othello_board_t board;
    othello_new(&board);
    int moves[SIZE][SIZE] = {0};

    ASSERT_EQ(4, valid_moves(&board, moves, PLAYER_A));
    ASSERT_EQ(4, valid_moves(&board, moves, PLAYER_B));
}

//Testing thtat correct winner is returned
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
    ASSERT_EQ(1, found_blank(&board, row, col));
}

//Testing that found_blank identifies if square is not blank
TEST(LogicTests, NotBlank) {
    int row = 4;
    int col = 4;
    othello_board_t board;
    othello_new(&board);
    ASSERT_EQ(0, found_blank(&board, row, col));
}

//Testing that counter was placed on the board for current player
TEST(LogicTests, PiecePlaced) {
    othello_board_t board;
    othello_new(&board);
    int row = 5;
    int col = 6;
    char piece[3] = "A";
    place_piece(&board, row, col, PLAYER_A);
    char pieceID[3] = {board.board[row][col]};
    ASSERT_EQ(0, found_blank(&board, row, col));
    ASSERT_STREQ(piece, pieceID);
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

//Testing that getScore returns correct score after counter is placed on the board
TEST(UtilityTests, UpdatedScore) {
    othello_board_t board;
    othello_new(&board);
    board.board[1][1] = PLAYER_A;
    ASSERT_EQ(3, getScore(&board, PLAYER_A));
    ASSERT_EQ(2, getScore(&board, PLAYER_B));
}

//Testing gameOver returns 0 if no valid moves left for either player
TEST(UtilityTests, gameOver) {
    othello_board_t board;
    othello_new(&board);
    for(int row = 0; row < SIZE; row++) {
        for(int col = 0; col < 0; col++) {
            board.board[row][col] = PLAYER_A;
        }
    }

    int tempMovesA[SIZE][SIZE] = {0};
    int tempMovesB[SIZE][SIZE] = {0};

    int numMovesA = 0;
    int numMovesB = 0;

    numMovesA = valid_moves(&board, tempMovesA, PLAYER_A);
    numMovesB = valid_moves(&board, tempMovesB, PLAYER_B);

    ASSERT_EQ(0, gameOver(&board));
}

//Testing that gameOver returns 1 if either player has valid moves left
TEST(UtilityTests, continueGame) {
    othello_board_t board;
    othello_new(&board);
    for(int row = 0; row < SIZE; row++) {
        for(int col = 0; col < SIZE; col++) {
            if(row == 1 || row == 5) {
                board.board[row][col] = PLAYER_A;
            }
        }
    }

    int tempMovesA[SIZE][SIZE] = {0};
    int tempMovesB[SIZE][SIZE] = {0};

    int numMovesA = 0;
    int numMovesB = 0;

    numMovesA = valid_moves(&board, tempMovesA, PLAYER_A);
    numMovesB = valid_moves(&board, tempMovesB, PLAYER_B);

    ASSERT_EQ(1, gameOver(&board));
}

//Testing that gameplay choice is stored correctly
TEST(UtilityTests, GameChoice) {
    char choice;
    getchar();
    printf("Use A for this test.\n");
    choice = game_choice();
    ASSERT_EQ(choice, 'A');
}

//Testing that if gameplay choice is A, B, or C then return 0
TEST(UtilityTests, ValidChoice) {
    char letter = 'A';
    char letter2 = 'B';
    char letter3 = 'C';
    ASSERT_EQ(0, valid_choice(letter));
    ASSERT_EQ(0, valid_choice(letter2));
    ASSERT_EQ(0, valid_choice(letter3));
}

//Testing that if gameplay choice is not A, B, or C then return 1
TEST(UtilityTests, InvalidChoice) {
    char letter = 'W';
    char letter2 = 'a';
    char letter3 = '5';
    ASSERT_EQ(1, valid_choice(letter));
    ASSERT_EQ(1, valid_choice(letter2));
    ASSERT_EQ(1, valid_choice(letter3));
}

//Testing that who_won() returns and increments game total if player A wins
TEST(UtilityTests, PlayerAWon) {
    int games_A = 0;
    int games_B = 0;
    int playerA_Score = 0;
    int playerB_Score = 0;

    othello_board_t board;
    othello_new(&board);

    board.board[7][7] = PLAYER_A;
    playerA_Score = getScore(&board, PLAYER_A);
    playerB_Score = getScore(&board, PLAYER_B);

    if(who_won(playerA_Score, playerB_Score) == 1) {
        games_A += 1;
    }

    ASSERT_EQ(1, who_won(playerA_Score, playerB_Score));
    ASSERT_EQ(1, games_A);
    ASSERT_EQ(0, games_B);
}

//Testing that who_won() returns and increments game total if player B wins
TEST(UtilityTests, PlayerBWon) {
    int games_A = 0;
    int games_B = 0;
    int playerA_Score = 0;
    int playerB_Score = 0;

    othello_board_t board;
    othello_new(&board);

    board.board[1][1] = PLAYER_B;
    board.board[2][3] = PLAYER_B;
    playerA_Score = getScore(&board, PLAYER_A);
    playerB_Score = getScore(&board, PLAYER_B);

    if(who_won(playerA_Score, playerB_Score) == 0) {
        games_B += 1;
    }

    ASSERT_EQ(0, who_won(playerA_Score, playerB_Score));
    ASSERT_EQ(1, games_B);
    ASSERT_EQ(0, games_A);
}

//Testing if correct difference value between players' scores is returned with initial board state
TEST(ComputerTests, InitialHeuristic) {
    othello_board_t board;
    othello_new(&board);
    ASSERT_EQ(0, heuristic(&board, PLAYER_A));
}

//Testing if correct difference value between players' scores is returned after more pieces are on the board
TEST(ComputerTests, MoreHeuristic) {
    othello_board_t board;
    othello_new(&board);
    board.board[5][6] = PLAYER_B;
    board.board[0][0] = PLAYER_B;
    ASSERT_EQ(2, heuristic(&board, PLAYER_B));
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
