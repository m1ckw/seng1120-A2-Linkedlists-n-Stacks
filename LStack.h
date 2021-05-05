
//*********************************************************************************************//
//  Class LStack (header)                                                                      //
//  Author: Mick Wiedermann                                                                    //
//  Course: SENG1120 | Assignment 2                                                            //
//  Date  : 2021-05-01                                                                         //
//  Program Description: Header file for the Stack Object.                                     //
//***********************************************************************************************

#ifndef LSTACK_H
#define LSTACK_H
#include <iostream>
#include "LinkedList.h"

using namespace std;

template<typename T>
class LStack 
{
    public:
        ////////// CONSTRUCTORS /////////////////////////

        // Precondition: None
		// Postcondition: A new instance of an empty stack is created.
		    // Stack height set to 0.
        LStack();  

        // Precondition: None
		// Postcondition: A new instance of a stack is created with a single element with the value passed.
        	// Stack size is incremented to 1.
        LStack(T &data);

        ////////// DESTRUCTOR ///////////////////////////

        // Precondition: A Stack element must exist. 
		// Postcondition: Deletes all elements on the stack.
        ~LStack();

        ////////// MUTATOR FUNCTIONS (SETTERS) //////////

        // Precondition: None, if no elements exist this function will create the first element.
		// Postcondition: Adds a element to the top of the stack.
        void push(T data);

        // Precondition: A element must already exist on the stack.  
		// Postcondition: The top element will be deleted and any data contained returned. 
        T pop();

        ////////// ACCESSOR FUNCTIONS (GETTERS) /////////

        // Precondition: A element exists on the stack and contains data.
		// Postcondition: Returns the data from the element on the top of the stack. 
        T peek();
		
        // Precondition: None. 
		// Postcondition: Returns the TRUE if the list is empty. 
		bool isEmpty();

        int size();
        

    private:
        LinkedList<T> *stack;                                   // Private member variable that points to the top element.
};

#include "LStack.hpp"
#endif