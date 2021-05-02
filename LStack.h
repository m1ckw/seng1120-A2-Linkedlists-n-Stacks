
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
		// Postcondition: Returns the hieght of the list. 
        const int size() const;

    private:
        LinkedList<T> *stack;                                   // Private member variable that points to the top element.
};
template<typename T>
ostream &operator << (ostream &output, LStack<T> &stack) {      // Non Member function that overloads the output operator.
	int height = stack.size();                                  // Sets the size variable to the current height of the stack.
    LStack<T> tempStack;                                        // Creates a temp stack to reorder after printing.
	for (int i=0; i < height; i++) {                            
		output << stack.peek() << "\n";                         // Retrives the data from the top element.
		tempStack.push(stack.pop());                            // Pushes the element above to the temp stack
    }
    for (int i=0; i < height; i++) {
        stack.push(tempStack.pop());                            // Pushes all elements onto the original stack in the original order.
    }
	return output;                                              // Returns the data from each element. 
}
#endif