//LinkedListDemo - Main Program
/******************************/ 
//Authors: Alex Mendes and Daniel Bell
//Course: SENG1120/6120
//Program Description: This program demonstrates the basic functionality of a Connect Four game. 

#include <iostream>
#include <cstdlib>
#include "GameplayStack.h"
#include "GamePiece.h"
//#include "Gameplay2DMatrix.h"

using namespace std;

int main()
{
    GameplayStack<GamePiece> game;
	// Gameplay2DMatrix<GamePiece> game;
	int gameToPlay = 4; // selects which game to play to test the code
	// 1 - plays only the vertical test
	// 2 - plays only the horizintal test
	// 3 - plays only the Tie Test
	// 4 - allows all 4 tests to run! 
	
	// Next are the sequences for four different games. Each one with a different outcome. 
	// Use the variable gameToPlay to select what you want to test.
	// GAME 3 will only work with the bonus question.
	
	if (gameToPlay == 1 || gameToPlay == 4)
	{ // GAME 1: O wins vertical

		game.initializeBoard();

		cout << "we got to here" << endl;

		game.play("X", 4); // place a "X" piece on the stack 3 (stacks are indexed 1 to 7)
		game.play("O", 5); game.play("X", 3); game.play("O", 5); game.play("X", 2); game.play("O", 1); 
		game.play("X", 4); game.play("O", 5); game.play("X", 3); game.play("O", 5);

		game.displayBoard();
	}
	
	if (gameToPlay == 2 || gameToPlay == 4)
	{ // GAME 2: X wins horizontal

	 	game.initializeBoard();

	 	game.play("X", 3); // place a "X" piece on the stack 3 (stacks are indexed 1 to 7)
	 	game.play("O", 5); game.play("X", 1); game.play("O", 6); game.play("X", 2); game.play("O", 4); 
	 	game.play("X", 7); game.play("O", 5); game.play("X", 3); game.play("O", 4); game.play("X", 3);
	 	game.play("O", 7); game.play("X", 2); game.play("O", 6);

	 	game.displayBoard();
	}
	
	if (gameToPlay == 3 || gameToPlay == 4)
	{ // GAME 3: Tie

		game.initializeBoard();

		game.play("X", 6); // place a "X" piece on the stack 6 (stacks are indexed 1 to 7)
		game.play("O", 5); game.play("X", 4); game.play("O", 6); game.play("X", 5); game.play("O", 4); 
		game.play("X", 3); game.play("O", 5); game.play("X", 7); game.play("O", 4); game.play("X", 3);
		game.play("O", 7); game.play("X", 3); game.play("O", 3); game.play("X", 6); game.play("O", 3);
		game.play("X", 4); game.play("O", 4); game.play("X", 2); game.play("O", 1); game.play("X", 7);
		game.play("O", 7); game.play("X", 6); game.play("O", 5); game.play("X", 2); game.play("O", 5);
		game.play("X", 6); game.play("O", 6); game.play("X", 5); game.play("O", 2); game.play("X", 1);
		game.play("O", 2); game.play("X", 2); game.play("O", 1); game.play("X", 1); game.play("O", 1);
		game.play("X", 1); game.play("O", 2); game.play("X", 7); game.play("O", 3); game.play("X", 4);
		game.play("O", 7);

		game.displayBoard();
	}
	
	cout << "The program has finished." << endl;
	return 0;
}
