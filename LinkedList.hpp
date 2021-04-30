//  Class LinkedList (header)                                                                  
//  Author: Mick Wiedermann                                                                    
//  Course: SENG1120 |                                                                         
//  Updated  : 2021-04-01                                                                      
//  Program Description: Header file for a doubly linked list Object. 					       


#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <iostream>
#include "Node.hpp"
using namespace std;

template<typename T>
class LinkedList
{
	public:
        ////////// TYPEDEF ////////////////////////////// 
		// Extension of the Node typedef to ensure data types match.
		//typedef Node::T T;

		////////// CONSTRUCTORS /////////////////////////

		// Precondition: None
		// Postcondition: A new instance of am empty linked list is created
		    // All pointers set to NUll, list length set to 0.
		LinkedList() {                                  // Creates an empty list setting all pointers to NULL.
			head = NULL;
			tail = NULL;
			current = NULL;
			length = 0;
		}

		// Precondition: None
		// Postcondition: A new instance of a linked list is created with a single node.
        	// All pointers set to the new node, list size incremented to 1.
		LinkedList(T& data) {                    // Creat a list with its first node.
			head = new Node<T>( data );
			tail = head;
			current = tail;
			length = 1;
		}

		////////// DESTRUCTOR ///////////////////////////

		// Precondition: A list item must exist. 
		// Postcondition: Deletes all nodes in the list.
		    // Calls the removeFromHead() function in a while loop removing each node from the head untill none remain.
		~LinkedList() {                                 // Loops through the list deleting the head until all nodes are deleted.
			while (head != NULL)
				removeFromHead();
			tail = NULL;
		}

		////////// MUTATOR FUNCTIONS (SETTERS) //////////

		// Precondition: None, if no nodes exist this will create the first node.
		// Postcondition: Adds a node to the head of the list and updates relevant pointers.
			// New heads previous to NULL, next to the existing node, and the existing nodes previous to the new head.
		void addToHead(const T data) {           // Adds a new node to the head of the list.
			if (length == 0) {                                      // Checks to see if the list is empty, if empty adds the first node.
				head = new Node<T>( data );
				tail = head;
				current = tail;
				length = 1;
			} else {
				Node<T>* headInsert = new Node<T>( data );                // Creates a new node on the heap.
				head->setPrevious( headInsert );                    // Sets the old heads previous pointer from NULL to the new head.
				headInsert->setNext( head );                        // Sets the new heads next pointer to the old head.
				head = headInsert;                                  // Sets the head pointer to the new head.
				head->setPrevious(NULL);                            // Sets the head previous to NULL.
				length++;                                           // Increments the length of the list by 1
				headInsert = NULL;                                  // Sets the temporary pointer to null.
			}
		}        

		// Precondition: None, if no nodes exist this will create the first node.
		// Postcondition: Adds a node to the tail of the list and updates relevant pointers.
			// New tails next to NULL, previous to the existing node, and the existing nodes next to the new tail.
		void addToTail(const T data) {           // Adds a new node to the tail of the list.
			if (length == 0) {                                      // Checks to see if the list is empty, if empty adds the first node.
				head = new Node<T>( data );
				tail = head;
				current = tail;
				length = 1;
			} else {
				Node<T>* tailInsert = new Node<T>( data );                // Creates a new node on the heap.
				tail->setNext( tailInsert );                        // Sets the old tails next pointer from NULL to the new tail.
				tailInsert->setPrevious( tail );                    // Sets the new tails previous pointer to the old tail.
				tail = tailInsert;                                  // Sets the tail pointer to the new tail.
				tail->setNext(NULL);                                // Sets the tails next to NULL.
				length++;                                           // Increments the length of the list by 1
				tailInsert = NULL;                                  // Sets the temporary pointer to null.
			}
		}        

		// Precondition: None, if no nodes exist this will create the first node.
		// Postcondition: Inserts a new node in front of the current pointers position, to the left.
			// Updates all relevant pointers of the insert node and the previous and next nodes. 
		void addToCurrent(const T data) {        // Inserts a new node between current and its previous.
			if (length == 0) {                                      // Checks to see if the list is empty, if empty adds the first node.
				head = new Node<T>( data );
				tail = head;
				current = tail;
				length = 1;
			} else if (length == 1) {
				addToHead(data);
			} else {
				Node<T>* currentInsert = new Node<T>( data );             // Creates a new node on the heap.
				currentInsert->setNext( current );                  // Sets the new nodes next pointer to current (link1).
				currentInsert->setPrevious(current->getPrevious()); // Sets the new nodes previous pointer to the previous node (Link3).
				current->setPrevious(currentInsert);                // Sets the current nodes previous pointer to the new node (link4).
				current = currentInsert->getPrevious();             // Moves the current pointer to the node previous.
				current->setNext(currentInsert);                    // Sets the previous nodes next pointer to the new node (link2).
				current = currentInsert->getNext();                 // Moves the current pointer back to its original position.
				length++;                                           // Increments the length of the list by 1.
				currentInsert = NULL;                               // Sets the temporary pointer to null.
			}
		}     

		// Precondition: A node must already exist.  
		// Postcondition: The head node will be deleted and any data contained returned. 
			// All pointers are updated on the existing node with the previous pointer set to NULL.
			// If no nodes are left all pointers will be set to NULL. 
		T removeFromHead() {         // Removes the head node from the linked list.
			T temp = head->getData();                        // Creates a temp node on the stack to store the head node data.
			if (length == 0) {                                      // Returns temp if the list is empty. 
				return temp;
			} else if (length == 1) {                               // Removes the head and sets all pointers to NULL if it's the only node.
				delete head;
				head = NULL;
				tail = NULL;
				current = NULL;
				length--;
			} else {                                                // If > 1 node, this will remove the node and adjust pointers.
				current = head;
				head = current->getNext();                          // Moves the head pointer to the next node.
				delete current;                                     // Deletes the head pointer.
				length--;                                           // Decrements the length of the list.
				current = head;                                     // Moves the current pointer to the head.
				head->setPrevious(NULL);                            // Set the heads prvious to NULL. 
			}
			return temp;                                            // Returns the deleted nodes data. 
		}

		// Precondition: A node must already exist. 
		// Postcondition: The tail node will be deleted and any data contained returned. 
			// All pointers are updated on the existing node with the next pointer set to NULL.
			// If no nodes are left all pointers will be set to NULL. 
		T removeFromTail() {         // Removes the tail node from the linked list.
			T temp = tail->getData();                        // Creates a temp node on the stack to store the tail node data.
			if (length == 0) {                                      // Returns temp if the list is empty. 
				return temp;
			}else if (length == 1) {                                // Removes the tail and sets all pointers to NULL if it's the only node.
				delete tail;
				head = NULL;
				tail = NULL;
				current = NULL;
				length--;
			} else {                                                // If > 1 node, this will remove the node and adjust pointers.
				current = tail;
				tail = current->getPrevious();
				delete current;
				length--;        
				current = head;
				tail->setNext(NULL);
			}
			return temp;
		}

		// Precondition: A node must already exist. 
		// Postcondition: The current node will be deleted and any data contained returned. 
			// All pointers are updated on the existing nodes both previous and/or next.
			// If no nodes are left all pointers will be set to NULL. 
		T removeFromCurrent() {      // Removes the node current is pointing to.
			T temp = current->getData();                     // Creates a TEMP data storage for the data type.
			if (length == 0) {                                      // Returns temp if the list is empty. 
				return temp;
			} else if (current == head) {                           // If the target is the head, invokes removeFromHead().
				removeFromHead();
			}else if (current == tail) {                            // If the target is the tail, invokes removeFromTail().
				removeFromTail();
			} else {
				Node<T>* targetDelete = current;                       // Creates a TEMP node pointer set to current.
				current = current->getPrevious();                   // Moves current to the previous node.
				current->setNext(targetDelete->getNext());          // Sets current next to skip deletion target.
				current = current->getNext();                       // Moves current to the node past the deletion target.
				current->setPrevious(targetDelete->getPrevious());  // Sets current previous to skip deletion target.
				delete targetDelete;                                // Deletes target
				length--;                                           // Decrements list length
				targetDelete = NULL;                                // sets the temp noe pointer to null
			}
			return temp;                                            // Returns the data from the deleted node.
		}
		
		////////// ACCESSOR FUNCTIONS (GETTERS) /////////

		// Precondition: A node exists and contains data.
		// Postcondition: Returns the data from the node that the current pointer is set to. 
		T getCurrentData() {             // Retrieves the data from the current node.
			return current->getData();
		}	

		// Precondition: A node exists and contains data.
		// Postcondition: Returns the data from the node that the Head pointer is set to. 
		T getHeadData() {             // Retrieves the data from the head node.
			return head->getData();
		}

		// Precondition: A node exists and contains data.
		// Postcondition: Returns the data from the node that the Tail pointer is set to. 
		T getTailData() {             // Retrieves the data from the head node.
			return tail->getData();
		}

		// Precondition: A list with more than one node exists.
		// Postcondition: The current pointer will be set to the head node. 
		void start() {                                  // Moves the current pointer to head.
			if (length == 0) {
				cout << "Error - No Nodes Exist" << endl;           // Sends error message if there are no nodes in the list.
			} else {
				current = head;
			}
		} 	                            

		// Precondition: A list with more than one node exists.
		// Postcondition: The current pointer will be set to the tail node. 
		void end() {                                    // Moves the current pointer to tail.
			if (length == 0) {
				cout << "Error - No Nodes Exist" << endl;           // Sends error message if there are no nodes in the list.
			} else {
				current = tail;
			}
		} 	                            

		// Precondition: A list with more than one node exists.
		// Postcondition: The current pointer will be moved one node to the right (the next node). 
		void forward() {                                // Moves the current pointer one node to the right.
			if (length == 0) {
				cout << "Error - No Nodes Exist" << endl;           // Sends error message if there are no nodes in the list.
			} else {
				current = current->getNext();
			}
		}                             

		// Precondition: A list with more than one node exists.
		// Postcondition: The current pointer will be moved one node to the left (the previous node). 
		void back() {                                   // moves current one node to the left.
			if (length == 0) {
				cout << "Error - No Nodes Exist" << endl;           // Sends error message if there are no nodes in the list.
			} else {
				current = current->getPrevious();
			}
		} 	                            

		// Precondition: None. 
		// Postcondition: Returns the length of the list. 
		const int getSize() const {                     // Returns the length of the current list. 
			return length;
		}

		/////////// MEMBER OPERATOR OVERLOAD ////////////
		// Precondition: Two lists must exists.
		// Postcondition: Concatenates the secondlist to the end of the first list. 
		void operator+= (LinkedList& list2) {		// Overloads the += operator to concatenate two lists into one.
			list2.start();                                          // Moves the current pointer to the head of the list to be added.
			int size = list2.getSize();                             // Stores the size of the list to be added in a local variable.
			for (int i=0; i < size; i++) {                          // For loop set to the size of the list.
				addToTail(list2.getCurrentData());					// Calls the addToTail function to add the data object one at a time.
				list2.forward();                                    // Moves the current pointer to the next node in the list to be added.
			}
		}
	
	private:
		Node<T>* head;												// Private member variable that points to the head node
		Node<T>* tail;												// Private member variable that points to the tail node
		Node<T>* current;											// Private member variable that points to the current node
		int length;													// Private member variable to track the length of the list.
};

#endif