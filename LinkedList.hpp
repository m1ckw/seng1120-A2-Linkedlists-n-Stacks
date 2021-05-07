
//*********************************************************************************************//
//  Class LinkedList (implementation)                                                          //
//  Author: Mick Wiedermann                                                                    //
//  Course: SENG1120 | Assignment 2                                                            //
//  Date  : 2021-05-01                                                                         //
//  Program Description: Implementation file for the Templated Doubly Linked List Object.      //
//***********************************************************************************************


////////// CONSTRUCTORS /////////////////////////
template <typename T>
LinkedList<T>::LinkedList() {                               // Creates an empty list setting all pointers to NULL.
    head = NULL;
    tail = NULL;
    current = NULL;
    length = 0;
}

template <typename T>
LinkedList<T>::LinkedList(T &data) {                        // Creates a list with its first node & increments the length +1.
    head = new Node<T>( data );
    tail = head;
    current = tail;
    length = 1;
}

////////// DESTRUCTOR ///////////////////////////
template <typename T>
LinkedList<T>::~LinkedList() {                              // Loops through the list deleting the head until all nodes are deleted.
    while (head != NULL)
        removeFromHead();
    tail = NULL;
}

////////// MUTATOR FUNCTIONS (SETTERS) //////////
template <typename T>
void LinkedList<T>::addToHead(const T data) {               // Adds a new node to the head of the list.
    if (length == 0) {                                      // Checks to see if the list is empty, if empty adds the first node.
        head = new Node<T>( data );
        tail = head;
        current = tail;
        length = 1;
    } else {
        Node<T>* headInsert = new Node<T>( data );			// Creates a new node on the heap.
        head->setPrevious( headInsert );                    // Sets the old heads previous pointer from NULL to the new head.
        headInsert->setNext( head );                        // Sets the new heads next pointer to the old head.
        head = headInsert;                                  // Sets the head pointer to the new head.
        head->setPrevious(NULL);                            // Sets the head previous to NULL.
        length++;                                           // Increments the length of the list by 1
        headInsert = NULL;                                  // Sets the temporary pointer to null.
    }
}

template <typename T>
void LinkedList<T>::addToTail(const T data) {               // Adds a new node to the tail of the list.
    if (length == 0) {                                      // Checks to see if the list is empty, if empty adds the first node.
        head = new Node<T>( data );
        tail = head;
        current = tail;
        length = 1;
    } else {
        Node<T>* tailInsert = new Node<T>( data );          // Creates a new node on the heap.
        tail->setNext( tailInsert );                        // Sets the old tails next pointer from NULL to the new tail.
        tailInsert->setPrevious( tail );                    // Sets the new tails previous pointer to the old tail.
        tail = tailInsert;                                  // Sets the tail pointer to the new tail.
        tail->setNext(NULL);                                // Sets the tails next to NULL.
        length++;                                           // Increments the length of the list by 1
        tailInsert = NULL;                                  // Sets the temporary pointer to null.
    }
}

template <typename T>
void LinkedList<T>::addToCurrent(const T data) {            // Inserts a new node between current and its previous.
    if (length == 0) {                                      // Checks to see if the list is empty, if empty adds the first node.
        head = new Node<T>( data );
        tail = head;
        current = tail;
        length = 1;
    } else if (length == 1) {
        addToHead(data);
    } else {
        Node<T>* currentInsert = new Node<T>( data );       // Creates a new node on the heap.
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

template <typename T>
T LinkedList<T>::removeFromHead() {                         // Removes the head node from the linked list.
    T temp = head->getData();                               // Creates a temp node on the stack to store the head node data.
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

template <typename T>
T LinkedList<T>::removeFromTail() {                         // Removes the tail node from the linked list.
    T temp = tail->getData();                               // Creates a temp node on the stack to store the tail node data.
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

template <typename T>
T LinkedList<T>::removeFromCurrent() {                      // Removes the node current is pointing to.
    T temp = current->getData();                            // Creates a TEMP data storage for the data type.
    if (length == 0) {                                      // Returns temp if the list is empty. 
        return temp;
    } else if (current == head) {                           // If the target is the head, invokes removeFromHead().
        removeFromHead();
    }else if (current == tail) {                            // If the target is the tail, invokes removeFromTail().
        removeFromTail();
    } else {
        Node<T>* targetDelete = current;                    // Creates a TEMP node pointer set to current.
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
template <typename T>
T LinkedList<T>::getCurrentData() {                         // Retrieves the data from the current node.
    return current->getData();
}

template <typename T>
T LinkedList<T>::getHeadData() {                            // Retrieves the data from the head node.
    return head->getData();
}

template <typename T>
T LinkedList<T>::getTailData() {                            // Retrieves the data from the head node.
    return tail->getData();
}

template <typename T>
void LinkedList<T>::start() {                               // Moves the current pointer to head.
    if (length == 0) {
        cout << "Error - No Nodes Exist" << endl;           // Sends error message if there are no nodes in the list.
    } else {
        current = head;
    }
}

template <typename T>
void LinkedList<T>::end() {                                 // Moves the current pointer to tail.
    if (length == 0) {
        cout << "Error - No Nodes Exist" << endl;           // Sends error message if there are no nodes in the list.
    } else {
        current = tail;
    }
}

template <typename T>
void LinkedList<T>::forward() {                             // Moves the current pointer one node to the right.
    if (length == 0) {
        cout << "Error - No Nodes Exist" << endl;           // Sends error message if there are no nodes in the list.
    } else {
        current = current->getNext();
    }
} 

template <typename T>
void LinkedList<T>::back() {                                // moves current one node to the left.
    if (length == 0) {
        cout << "Error - No Nodes Exist" << endl;           // Sends error message if there are no nodes in the list.
    } else {
        current = current->getPrevious();
    }
}

template <typename T> 
const int LinkedList<T>::getSize() const {                  // Returns the length of the current list. 
    return length;
}

template <typename T>
void LinkedList<T>::operator+= (LinkedList& list2) {		// Overloads the += operator to concatenate two lists into one.
    list2.start();                                          // Moves the current pointer to the head of the list to be added.
    int size = list2.getSize();                             // Stores the size of the list to be added in a local variable.
    for (int i=0; i < size; i++) {                          // For loop set to the size of the list.
        addToTail(list2.getCurrentData());					// Calls the addToTail function to add the data object one at a time.
        list2.forward();                                    // Moves the current pointer to the next node in the list to be added.
    }
}


