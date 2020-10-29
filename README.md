# Othello

Othello, also known as Reversi, is a strategy board game played on an 8x8 board. The object of the game is to have the majority of disks flipped to display your color when the last playable empty square is filled.

## Compiling the Code
Run

```
cmake .
make
```

## Running the Game

Run `./bin/othello`

## Game Tutorial
Othello can be played by two human players or one human player versus the computer. On every turn, the current player and both player's score are shown at the top of the screen. Players are also shown the current state of the board each turn. 

To start, the board is initialized with 2 of each player's pieces at the center of the board. Valid plays are shown on the board by an asterisk mark. The player should input the position of where they want to place a piece by inputting the row and column separated by a single space (eg: 2 4).

A valid move is one where a player flips at least one of the opponent's piece by flanking it.

The game ends when there are no moves left for both players or when the board is completely filled.

## Structure
**logic.c/h**
* Explain

**gameboard.c/h**
* Explain

**player.c/h**
* Explain

**utlity.c/h**
* Explain

**othello.c**
* Explain

## Running the Tests

Run

```
cmake .
make

```
Run `./bin/othello_tests`
