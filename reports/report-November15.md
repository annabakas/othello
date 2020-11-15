# Week 5 Report

### computer.c 
**Recap**
* This week, I worked on implementing the minimax algorithm, which is where the computer calculates its next best move by evaluating the state of the board several moves down the road. The computer assumes that the opponent, in this case the human player, always selects the best move, which in turn minimizes the score for the computer. My minimax implementation is based on: http://www.cse.uaa.alaska.edu/~afkjm/csce211/handouts/othello-minimax.pdf.
* A problem that I ran into this week while implementing the minimax algorithm was that my gameplay kept hanging in an infinite loop. To figure out why this was occurring, I used GDB and print statements. Eventually, I realized it was because I didn't check in minimaxVal() if the board was filled up i.e. each player had no valid moves left. I solved this by creating gameOver() in utility.c.
**heuristic()** 
* In heuristic(), the current state of the board and player indicator are passed in as parameters. I set the opponent and then grab the player's and opponent's scores using getScore(). I then return the player score minus the opponent score.
**minimaxVal()** 
* In minimaxVal(), the temporary board, char original turn, char current turn, and search value are passed in as parameters. This is a recursive function. The original turn parameter determines if it's a minimizing or maximizing move. The search parameter controls when we stop searching. First, I set the lookahead equal to 6, but it can be changed. If search equals 6 or gameOver(tempBoard) returns 0, the value from heuristic(tempBoard, origTurn) is returned. gameOver() is a function in utility.c that returns 0 if both the computer player and human player have 0 valid moves left. heuristic() returns the origTurn's score minus its opponent's score. After this if statement, I grab the valid moves for currentTurn by calling valid_moves with tempBoard, tempMoves, and currentTurn as parameters. I store the return value in numMoves. If numMoves is equal to zero, I skip to the next player by returning minimaxVal(tempBoard, origTurn, opponent, search + 1). If there are valid moves, I set bestMoveScore = -99999 to find the max. If origTurn does not equal currentTurn, I set bestMoveScore = 99999 to find the min. Then, I loop through all the valid moves from tempMoves, skipping invalid moves. While looping through the valid moves, I create a newTempBoard, copy the state of the tempBoard into newTempBoard with copy_board(), and place currentTurn's valid piece onto the newTempBoard using make_move(). Then, I make a recursive call minimaxVal(&newTempBoard, origTurn, opponent, search + 1), storing the value in val. If the origTurn is equal to currentTurn, I want to remember the max. So, if val > bestMoveScore, I save val in bestMoveScore. If origTurn does not equal currentturn, I want to remember the min. So, if val < bestMoveScore, I store val in bestMoveScore. Once we are out of the two for loops, I return the bestMoveScore.
**minimax()**
* In minimax(), a temporary board is created called tempBoard. Then, we loop through the valid moves array and ignore moves/coordinates that are invalid. While traversing the matrix of valid moves, the current state of the board is copied into tempBoard using copy_board(). Then, a valid move is placed onto the tempBoard using make_move(). After this, minimaxVal() is called with the temporary board, whose turn it is, who the opponent is, and the search value (which is 1 to start) passed as parameters. If the value returned from minimaxVal is greater than the current bestMoveScore, it's set to the bestMoveScore and that row and column are set to the best row and best column. Once we are out of the two for loops, the current state of the board, best row, best column, and current player indicator is passed into make_move() to place the computer's counter on the board.

### othello_tests.cc
**gameOver**
* I created another UtilityTest called gameOver which tests that gameOver returns 0 if no valid moves are left for each player. I created and initialized a new board. I then filled the entire board with PLAYER_A's counter. After, I called valid_moves() for player A and player B and stored each of the return values in an int variable. Then, I did ASSERT_EQ(0, gameOver(&board)), where board is the current state of the board.
**continueGame**
* I created another UtilityTest called continueGame which tests that gameOver returns 1 if either play has valid moves left. I created and initialized a new board. I then filled row 1 and row 5 with PLAYER_A's counter. After, I called valid_moves() for player A and player B and stored of the return values in an int variable. Then, I did ASSERT_EQ(1, gameOver(&board)), where board is the current state of the board.
**InitialHeuristic**
* For ComputerTests, I created a test called InitialHeuristic, which tests if the correct difference between players' scores is returned with the current board state being the initial board state. I created and initialized a new board. Then, I did ASSERT_EQ(0, heuristic(&board, PLAYER_A)) where board is the current state of the board and PLAYER_A is the current player.
**MoreHeuristic**
* For ComputerTests, I created a test called MoreHeuristic, which tests if the correct difference between players' scores is returned after more pieces are placed on the board. I created and initialized a new board. Then, I placed two more PLAYER_B counters on the board. After, I did ASSERT_EQ(2, heuristic(&board, PLAYER_B)) where board is the current state of the board and PLAYER_B is the current player.

### othello.c
* In othello.c, I got rid of the code for the human player in the else statement. Now, I check if there are valid moves for the computer, display the current state of the board, set invalid moves to 0, call minimax(&board, moves, other), clear the playable moves from the board, and increment total moves by 1.

### gameboard.c
* I moved copy_board() from computer.c to gameboard.c because since it dealt more with the gameboard itself, I thought it best to be with the other gameboard-related functions.

# Plan for Week 6
* This week I am going to continue working on Milestone 3. I want to do some code clean-up and make more tests. I also want to try to start implementing a time limit for the human-computer play.

# Demo
