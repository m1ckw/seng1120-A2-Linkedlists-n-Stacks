
#include <iostream>
#include <stdio.h> // To generate a random number
#include <cstdlib> // Provides access to the NULL pointer 
#include "GameplayStack.h"

using namespace std;

template<typename T>
GameplayStack<T>::GameplayStack() {
    LStack<T> *gameArray[7];
    for (int i = 0; i < 6; i++) {
        gameArray[i] = new LStack<T>;
    }
}     

template<typename T>
GameplayStack<T>::~GameplayStack() {
    for (int i = 0; i < 6; i++) {
        delete LStack<T> gameArray[i];
    } 
    delete LStack<T> gameArray[7];
}

template<typename T>
void GameplayStack<T>::initializeBoard() {
    for (int i=0; i < 6; i++) {
        if (gameArray[i]->LStack<T>::size() > 0) {
            gameArray[i] = ~LStack();
            gameArray[i] = new LStack<T>;
        }
    } 
} 

template<typename T>
void GameplayStack<T>::play(const string value, int stackNum) {
    int i = 1;
    while (gameArray[i] != gameArray[stackNum]) {
        i++;
    }
    gameArray[i]->LStack<T>::push(GamePiece::set_value(value));
} 
        
template<typename T>        
T GameplayStack<T>::displayBoard() {

    return this;
}



