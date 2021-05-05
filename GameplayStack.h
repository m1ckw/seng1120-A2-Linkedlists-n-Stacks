
//*********************************************************************************************//
//  Class GameplayStack (header)                                                               //
//  Author: Mick Wiedermann                                                                    //
//  Course: SENG1120 | Assignment 2                                                            //
//  Date  : 2021-05-01                                                                         //
//  Program Description: Header file for the GameplayStack Object.                             //
//***********************************************************************************************

#ifndef GPSTACK_H
#define GPSTACK_H
#include <iostream>
#include <cstdlib> 
#include "LStack.h"
//#include "GamePiece.h"

using namespace std;

template<typename T>
class GameplayStack
{
    public:
        ////////// CONSTRUCTOR /////////////////////////

        
        GameplayStack();   

        ////////// DESTRUCTOR ///////////////////////////


        ~GameplayStack(); 

        ////////// MUTATOR FUNCTIONS (SETTERS) //////////


        void initializeBoard();  


        void play(string value, int stackNum); 
        
        ////////// ACCESSOR FUNCTIONS (GETTERS) /////////

        
        void displayBoard();

    private:
        LStack<T> *gameArray[7];

};
#include "GameplayStack.hpp"
#endif 