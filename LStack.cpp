
//*********************************************************************************************//
//  Class LStack (implementation)                                                              //
//  Author: Mick Wiedermann                                                                    //
//  Course: SENG1120 | Assignment 2                                                            //
//  Date  : 2021-05-01                                                                         //
//  Program Description: Implementation file for the Stack Object.                             //
//***********************************************************************************************

#include <iostream>
#include "LStack.h"

////////// CONSTRUCTORS /////////////////////////
template<typename T>
LStack<T>::LStack() {                                       // Instantiates an empty stack on the heap 
    stack = new LinkedList<T>;                                  
}

template<typename T>
LStack<T>::LStack(T &data) {                                // Instantiates a stack on the heap with one element containing data
    stack = new LinkedList<T>(data);
}

////////// DESTRUCTOR ///////////////////////////
template<typename T>
LStack<T>::~LStack() {                                      // Deletes the stack 
    delete stack;
}

////////// MUTATOR FUNCTIONS (SETTERS) //////////
template<typename T>
void LStack<T>::push(T data) {                              // Pushes a new element onto the stack containing the data passed
    stack->addToHead(data);
}

template<typename T>
T LStack<T>::pop() {                                        // Removes the element from the top of the stack and returns the data
    return stack->removeFromHead();
}

////////// ACCESSOR FUNCTIONS (GETTERS) /////////
template<typename T>
T LStack<T>::peek() {                                       // Returns the data stored in the top element on the stack.
    return stack->getHeadData();
} 

template<typename T>
const int LStack<T>::size() const {                         // Returns the current height of the stack
    return stack->getSize();
}

