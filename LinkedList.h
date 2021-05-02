
//*********************************************************************************************//
//  Class LinkedList (header)                                                                  //
//  Author: Mick Wiedermann                                                                    //
//  Course: SENG1120 | Assignment 2                                                            //
//  Date  : 2021-05-01                                                                         //
//  Program Description: Header file for the doubly linked list Object. 					   //
//***********************************************************************************************

#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <iostream>
#include "Node.h"

using namespace std;

template <typename T>
class LinkedList
{
	public:
		////////// CONSTRUCTORS /////////////////////////

		// Precondition: None
		// Postcondition: A new instance of an empty linked list is created
		    // All pointers set to NUll, list length set to 0.
		LinkedList();

		// Precondition: None
		// Postcondition: A new instance of a linked list is created with a single node.
        	// All pointers set to the new node, list size incremented to 1.
		LinkedList(T& data);

		////////// DESTRUCTOR ///////////////////////////

		// Precondition: A list item must exist. 
		// Postcondition: Deletes all nodes in the list.
		    // Calls the removeFromHead() function in a while loop removing each node from the head untill none remain.
		~LinkedList();

		////////// MUTATOR FUNCTIONS (SETTERS) //////////

		// Precondition: None, if no nodes exist this will create the first node.
		// Postcondition: Adds a node to the head of the list and updates relevant pointers.
			// New heads previous to NULL, next to the existing node, and the existing nodes previous to the new head.
		void addToHead(const T data);        

		// Precondition: None, if no nodes exist this will create the first node.
		// Postcondition: Adds a node to the tail of the list and updates relevant pointers.
			// New tails next to NULL, previous to the existing node, and the existing nodes next to the new tail.
		void addToTail(const T data);        

		// Precondition: None, if no nodes exist this will create the first node.
		// Postcondition: Inserts a new node in front of the current pointers position, to the left.
			// Updates all relevant pointers of the insert node and the previous and next nodes. 
		void addToCurrent(const T data);    

		// Precondition: A node must already exist.  
		// Postcondition: The head node will be deleted and any data contained returned. 
			// All pointers are updated on the existing node with the previous pointer set to NULL.
			// If no nodes are left all pointers will be set to NULL. 
		T removeFromHead();

		// Precondition: A node must already exist. 
		// Postcondition: The tail node will be deleted and any data contained returned. 
			// All pointers are updated on the existing node with the next pointer set to NULL.
			// If no nodes are left all pointers will be set to NULL. 
		T removeFromTail();

		// Precondition: A node must already exist. 
		// Postcondition: The current node will be deleted and any data contained returned. 
			// All pointers are updated on the existing nodes both previous and/or next.
			// If no nodes are left all pointers will be set to NULL. 
		T removeFromCurrent();
		
		////////// ACCESSOR FUNCTIONS (GETTERS) /////////

		// Precondition: A node exists and contains data.
		// Postcondition: Returns the data from the node that the current pointer is set to. 
		T getCurrentData();	

		// Precondition: A node exists and contains data.
		// Postcondition: Returns the data from the node that the Head pointer is set to. 
		T getHeadData();

		// Precondition: A node exists and contains data.
		// Postcondition: Returns the data from the node that the Tail pointer is set to. 
		T getTailData();

		// Precondition: A list with more than one node exists.
		// Postcondition: The current pointer will be set to the head node. 
		void start(); 	                            

		// Precondition: A list with more than one node exists.
		// Postcondition: The current pointer will be set to the tail node. 
		void end(); 	                            

		// Precondition: A list with more than one node exists.
		// Postcondition: The current pointer will be moved one node to the right (the next node). 
		void forward();                            

		// Precondition: A list with more than one node exists.
		// Postcondition: The current pointer will be moved one node to the left (the previous node). 
		void back();	                            

		// Precondition: None. 
		// Postcondition: Returns the length of the list. 
		const int getSize() const;

		/////////// MEMBER OPERATOR OVERLOAD ////////////
		// Precondition: Two lists must exists.
		// Postcondition: Concatenates the secondlist to the end of the first list. 
		void operator+= (LinkedList& list2);
	
	private:
		Node<T> *head;												// Private member variable that points to the head node
		Node<T> *tail;												// Private member variable that points to the tail node
		Node<T> *current;											// Private member variable that points to the current node
		int length;													// Private member variable to track the length of the list.
};

#endif