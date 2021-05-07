
//*********************************************************************************************//
//  Class GameplayStack (header)                                                               //
//  Author: Mick Wiedermann                                                                    //
//  Course: SENG1120 | Assignment 2                                                            //
//  Date  : 2021-05-01                                                                         //
//  Program Description: Templated Header file for the GameplayStack Object.                   //
//***********************************************************************************************

#ifndef GPSTACK_H
#define GPSTACK_H
#include <iostream>
#include <cstdlib> 
#include "LStack.h"

using namespace std;

template<typename T>
class GameplayStack
{
    public:
        ////////// CONSTRUCTOR /////////////////////////

        // Precondition: None
		// Postcondition: Seven new instances of an empty LStack are created on the heap.
            // A seven element array of LStack pointers track each of the LStacks.   
        GameplayStack();   

        ////////// DESTRUCTOR ///////////////////////////

        // Precondition: A GameplayStack Object must exist. 
		// Postcondition: Deletes all Stacks on the Heap.
        ~GameplayStack(); 

        ////////// MUTATOR FUNCTIONS (SETTERS) //////////

        // Precondition: A GameplayStack Object must exist.
		// Postcondition: Checks each of the seven stacks removing any existing elements ready for a new game. 
        void initializeBoard();  

        // Precondition: A GameplayStack Object must exist.
		// Postcondition: Searches for the matching stackNumber 1-7 then places the game piece 'value' on that stack. 
        void play(const string value, int stackNum); 
        
        ////////// ACCESSOR FUNCTIONS (GETTERS) /////////

        // Precondition: A GameplayStack Object exists.
		// Postcondition: Displays the current state of the game board when called.
            // Will not display game pieces on the stack higher than the first six as per the game scope.
        void displayBoard();

    private:
        LStack<T> *gameArray[7];                                // Private member array of LStack pointers. 

};

#include "GameplayStack.hpp"
#endif 