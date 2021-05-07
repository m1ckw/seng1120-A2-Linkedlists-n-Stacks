
//*********************************************************************************************//
//  Class Node (header)                                                                        //
//  Author: Mick Wiedermann                                                                    //
//  Course: SENG1120 | Assignment 2                                                            //
//  Date  : 2021-05-01                                                                         //
//  Program Description: Templated Header file for the Node Object.                            //
//***********************************************************************************************

#ifndef MICK_NODE
#define MICK_NODE
#include <cstdlib> // Provides access to the NULL pointer 
using namespace std;

template <typename T>
class Node
{
    public:
        ////////// CONSTRUCTORS /////////////////////////

        // Precondition: None.
        // Postcondition: An empty node is created with the previous and next pointers set to NULL. 
        Node();

        // Precondition: None. 
        // Postcondition: A new node is created and initialised with the data passed.
        Node(const T& initData, Node* initNext = NULL, Node* initPrevious = NULL);


        ////////// DESTRUCTOR ///////////////////////////

        // Precondition: A node must exist. 
        // Postcondition: Deletes the node and sets the next and previous pointers to NULL.
        ~Node();

        ////////// MUTATOR FUNCTIONS (SETTERS) //////////

        // Precondition: A node must exist.
        // Postcondition: Updates the data within the node to the data passed. 
        void setData(const T& newData);

        // Precondition: A node must exist. 
        // Postcondition: Sets the current nodes next pointer to the location passed. 
        void setNext (Node* nextLink);  

        // Precondition: A node must exist. 
        // Postcondition: Sets the current nodes previous pointer to the location passed.           
        void setPrevious (Node* previousLink); 

        ////////// ACCESSOR FUNCTIONS (GETTERS) /////////

        // Precondition: A node containing data must exist.
        // Postcondition: The data from the target node is returned.  
        const T getData() const;

        // Precondition: More than one node must exist.  
        // Postcondition: Returns the location of the next CONST node.
        const Node* getNext() const;

        // Precondition: More than one node must exist. 
        // Postcondition: Returns the location of the next node.                
        Node* getNext();

        // Precondition: More than one node must exist.  
        // Postcondition: Returns the location of the previous CONST node.
        const Node* getPrevious() const;

        // Precondition: More than one node must exist. 
        // Postcondition: Returns the location of the previous node.
        Node* getPrevious();                           

    private:
        T data;                            	 // Private member variable that stores the data types data.
        Node* next;                          // Private member variable that points to the next node.   
        Node* previous;                      // Private member variable that points to the next node.

};

#include "Node.hpp"
#endif