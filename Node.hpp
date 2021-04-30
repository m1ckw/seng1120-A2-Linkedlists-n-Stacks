// Node class to implement a linked list 

#ifndef MICK_NODE
#define MICK_NODE
#include <cstdlib> // Provides access to the NULL pointer 
using namespace std;

template <typename T>
class Node
{
    public:
        ////////// TYPEDEF ////////////////////////////// 
        //typedef int dataType;

        ////////// CONSTRUCTORS /////////////////////////

        // Precondition: None.
        // Postcondition: An empty node is created with the previous and next pointers set to NULL. 
        Node()
        {
            next = NULL;
            previous = NULL;
        }

        // Precondition: None. 
        // Postcondition: A new node is created and initialised with the data passed.
        Node(const T& initData, Node* initNext = NULL, Node* initPrevious = NULL)
		{
            data = initData;
            next = initNext;
            previous = initPrevious;
        }
        ////////// DESTRUCTOR ///////////////////////////

        // Precondition: A node must exist. 
        // Postcondition: Deletes the node and sets the next and previous pointers to NULL.
        ~Node() 
        {
            next = NULL;
            previous = NULL;
        }

        ////////// MUTATOR FUNCTIONS (SETTERS) //////////

        // Precondition: A node must exist.
        // Postcondition: Updates the data within the node to the data passed. 
        void setData(const T& newData)  
        {
            data = newData;
        }

        // Precondition: A node must exist. 
        // Postcondition: Sets the current nodes next pointer to the location passed. 
        void setNext (Node* nextLink)               
        {
            next = nextLink;
        }   

        // Precondition: A node must exist. 
        // Postcondition: Sets the current nodes previous pointer to the location passed.           
        void setPrevious (Node* previousLink)       
        {
            previous = previousLink;
        }  

        ////////// ACCESSOR FUNCTIONS (GETTERS) /////////

        // Precondition: A node containing data must exist.
        // Postcondition: The data from the target node is returned.  
        const T getData() const
        {
            return data;
        }

        // Precondition: More than one node must exist.  
        // Postcondition: Returns the location of the next CONST node.
        const T getNext() const                 
        {
            return next;
        }

        // Precondition: More than one node must exist. 
        // Postcondition: Returns the location of the next node.                
        Node* getNext()                             
        {
            return next;
        } 

        // Precondition: More than one node must exist.  
        // Postcondition: Returns the location of the previous CONST node.
        const Node* getPrevious() const             
        {
            return previous;
        } 

        // Precondition: More than one node must exist. 
        // Postcondition: Returns the location of the previous node.
        Node* getPrevious()                         
        {
            return previous;
        }                           

    private:
        T data;                             // Private member variable that stores the data types data.
        Node* next;                          // Private member variable that points to the next node.   
        Node* previous;                      // Private member variable that points to the next node.

};


#endif