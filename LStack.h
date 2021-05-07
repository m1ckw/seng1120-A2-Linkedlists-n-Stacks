
//*********************************************************************************************//
//  Class LStack (header)                                                                      //
//  Author: Mick Wiedermann                                                                    //
//  Course: SENG1120 | Assignment 2                                                            //
//  Date  : 2021-05-01                                                                         //
//  Program Description: Templated Header file for the Stack Object built on the LinkedList.   //
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
		    // Stack height (LinkedList) set to 0.
        LStack();  

        // Precondition: None
		// Postcondition: A new instance of a stack is created with a single element containing the value passed.
        	// Stack height (LinkedList) is incremented by 1.
        LStack(T &data);

        ////////// DESTRUCTOR ///////////////////////////

        // Precondition: A Stack element must exist. 
		// Postcondition: Deletes all elements on the stack.
        ~LStack();

        ////////// MUTATOR FUNCTIONS (SETTERS) //////////

        // Precondition: None, if no elements exist this function will create the first element.
		// Postcondition: Adds a element to the top of the stack.
        void push(const T data);

        // Precondition: A element must already exist on the stack.  
		// Postcondition: The top element will be removed and any data contained returned. 
            // // Stack height (LinkedList) is decremented by 1.
        T pop() const;

        ////////// ACCESSOR FUNCTIONS (GETTERS) /////////

        // Precondition: A element exists on the stack and contains data.
		// Postcondition: Returns the data from the element on the top of the stack. 
        T peek() const;
		
        // Precondition: None. 
		// Postcondition: Returns the TRUE if the list is empty. 
		bool isEmpty(); 

    private:
        LinkedList<T> *list;                                   // Private member variable that points to a LinkedList.
};

#include "LStack.hpp"
#endif