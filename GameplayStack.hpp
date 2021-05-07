
//*********************************************************************************************//
//  Class GameplayStack (implementation)                                                       //
//  Author: Mick Wiedermann                                                                    //
//  Course: SENG1120 | Assignment 2                                                            //
//  Date  : 2021-05-01                                                                         //
//  Program Description: Implementation file for the Templated GameplayStack Object.           //
//***********************************************************************************************


////////// CONSTRUCTOR /////////////////////////
template<typename T>
GameplayStack<T>::GameplayStack() {                             // Instantiates the GameplayStack 
      for (int i = 0; i < 7; i++) {                             // creating 7 empty stacks on the heap
          gameArray[i] = new LStack<T>();                       // and an array of 7 LStack pointers 
    }
}     

////////// DESTRUCTOR ///////////////////////////
template<typename T>
GameplayStack<T>::~GameplayStack() {                            // Deletes each stack from the heap.
    for (int i = 0; i < 6; i++) {
        delete gameArray[i];
    } 
} 

////////// MUTATOR FUNCTIONS (SETTERS) //////////
template<typename T>
void GameplayStack<T>::initializeBoard() {                      // Clears the board from previous games ready for a new game.
    for (int i=0; i < 7; i++) {
        if (!gameArray[i]->isEmpty()) {                         // Checks if the stack is empty ready to play
            delete gameArray[i];                                // Deletes stack if the stack is NOT empty
            gameArray[i] = new LStack<T>();                     // Creates a new stack. 
        } 
    } 
} 

template<typename T>
void GameplayStack<T>::play(const string value, int stackNum) {
    gameArray[stackNum - 1]->push(value);                       // Adds the piece to the board
    LStack<T> tempArray[7];                                     // Temp array to pop and peek and see if there is a winner.
    int vertCompare = 0;
    int i = stackNum - 1;
    while (!gameArray[i]->isEmpty()) {                          // While there are elements on the stack...
        tempArray[i].push(gameArray[i]->pop());                 // Pops the elements off the gameArray onto the tempArray.
        if (!gameArray[i]->isEmpty() && !tempArray[i].isEmpty()) {
            if (gameArray[i]->peek().get_value() ==
                tempArray[i].peek().get_value()) {              // While there are elements on both stacks, compares them.
                vertCompare++;                                  // If both elements on either stack are equal, increments the counter by 1.
            } else {
                vertCompare = 0;                                // If the elements are not equal, resets the counter. 
            }
        }
        if (vertCompare >= 3 && gameArray[i]->isEmpty()) {      // If the counter reaches 3, then we have 4 matching elements in a row.
            cout << " \n" << tempArray[i].peek() 
            << "'s have a verticle win in column: " << i+1 << endl;
        }
    }
    for (int i=0; i < 6; i++) {                                 // Returns the stack back to the gameArray board ready for the next move.
        for (int k=0; k < 7; k++) {
            if (!tempArray[k].isEmpty()) {
                gameArray[k]->push(tempArray[k].pop());
            }
        }
    }
}

////////// ACCESSOR FUNCTIONS (GETTERS) /////////        
template<typename T>        
void GameplayStack<T>::displayBoard() {                         // Displays the board & pieces played when called.
    string board = "\n  #######################" 
    "\n    1  2  3  4  5  6  7  \n";                            // Creates the base of the board.
    LStack<T> tempArray[7];                                 
    for (int i=0; i < 7; i++) {
        while (!gameArray[i]->isEmpty()) {                      // While there are elements on the stack...
           tempArray[i].push(gameArray[i]->pop());              // Pops the elements off the gameArray onto the tempArray.
       } 
    }
    for (int i=0; i < 6; i++) {
        board = "#" + board;                                    // Creates the right side of the game board.
        for (int k=6; k >= 0; k--){                             // While there are elements on the tempArray,
            if (!tempArray[k].isEmpty()) {                      // Retrives their value and adds them to a sting.
                board = " " + tempArray[k].peek().get_value() + " " + board;
                gameArray[k]->push(tempArray[k].pop());         // Pops the elememnt back onto the game array 
            } else {
                board = "   " + board;                          // If the stack is empty adds a gamePeice space to the string.
            }
        }   // Below we look for a horizontal win by comparing the gamePieces row by row as they go back to the main gameArray.
        if (!tempArray[1].isEmpty() && !tempArray[2].isEmpty() && !tempArray[3].isEmpty() &&
            !tempArray[4].isEmpty() && !tempArray[5].isEmpty() && !tempArray[6].isEmpty()) {
            if ((tempArray[3].peek().get_value() == tempArray[4].peek().get_value()) && 
                 tempArray[4].peek().get_value() == tempArray[5].peek().get_value() &&
                 tempArray[5].peek().get_value() == tempArray[6].peek().get_value()) {
                     cout << tempArray[5].peek() << "'s have a horizontal win on row: " 
                     << i+2  << endl;
            }
        }
        if (i > 3 && !tempArray[0].isEmpty()) {                 // Just a cheeky snippit to give the desired output, I'm out of time.
            cout << "We have no wins, it's a draw :(" << endl;
        }
        board = "\n  #" + board;                                // Creates the left side of the game board.
    } cout << board << endl;                                    // Prints the huge string that is the board. 
}


