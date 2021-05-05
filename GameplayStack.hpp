
//*********************************************************************************************//
//  Class GameplayStack (implementation)                                                       //
//  Author: Mick Wiedermann                                                                    //
//  Course: SENG1120 | Assignment 2                                                            //
//  Date  : 2021-05-01                                                                         //
//  Program Description: Implementation file for the GameplayStack Object.                     //
//***********************************************************************************************


template<typename T>
GameplayStack<T>::GameplayStack() {
      for (int i = 0; i < 7; i++) {
          gameArray[i] = new LStack<T>();
    }
}     

template<typename T>
GameplayStack<T>::~GameplayStack() {
    for (int i = 0; i < 6; i++) {
        delete gameArray[i];
    } 
} 

template<typename T>
void GameplayStack<T>::initializeBoard() {
    for (int i=0; i < 7; i++) {
        if (!gameArray[i]->isEmpty()) {
            delete gameArray[i];
            gameArray[i] = new LStack<T>();
        } 
    } 
} 

template<typename T>
void GameplayStack<T>::play(const string value, int stackNum) {
    gameArray[stackNum - 1]->push(value);
} 
        
template<typename T>        
void GameplayStack<T>::displayBoard() {                         // Displays the board & pieces at the completion of the game.
    string board = "\n  #######################" 
    "\n    1  2  3  4  5  6  7  \n";                            // Creates the base of the board.
    LStack<T> tempArray[7];                                 
    for (int i=0; i < 7; i++) {
       while (!gameArray[i]->isEmpty()) {                       // While there are elements on the stack...
           tempArray[i].push(gameArray[i]->pop());              // Pops the elements off the gameArray onto the tempArray.
       } 
    }
    for (int i=0; i < 7; i++) {
        board = "#" + board;                                    // Creates the right side of the game board.
        for (int k=6; k >= 0; k--){
            if (!tempArray[k].isEmpty()) {
                board = " " + tempArray[k].peek().get_value() + " " + board;
                gameArray[k]->push(tempArray[k].pop());
            } else {
                board = "   " + board;
            }
        } 
        board = "\n  #" + board;                                // Creates the left side of the game board.
    } cout << board << endl;
}


