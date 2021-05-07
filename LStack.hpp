
//*********************************************************************************************//
//  Class LStack (implementation)                                                              //
//  Author: Mick Wiedermann                                                                    //
//  Course: SENG1120 | Assignment 2                                                            //
//  Date  : 2021-05-01                                                                         //
//  Program Description: Implementation file for the Templated Stack Object.                   //
//***********************************************************************************************


////////// CONSTRUCTORS /////////////////////////
template<typename T>
LStack<T>::LStack() {                                       // Instantiates an empty stack on the heap. 
    list = new LinkedList<T>;                                  
}

template<typename T>
LStack<T>::LStack(T &data) {                                // Instantiates a stack on the heap with one element containing data.
    list = new LinkedList<T>(data);
}

////////// DESTRUCTOR ///////////////////////////
template<typename T>
LStack<T>::~LStack() {                                      // Deletes the stack.
    delete list;
}

////////// MUTATOR FUNCTIONS (SETTERS) //////////
template<typename T>
void LStack<T>::push(const T data) {                        // Pushes a new element onto the stack containing the data passed.
    list->addToHead(data);
}

template<typename T>
T LStack<T>::pop() const {                                  // Removes the element from the top of the stack and returns the data.
    return list->removeFromHead();
}

////////// ACCESSOR FUNCTIONS (GETTERS) /////////
template<typename T>
T LStack<T>::peek() const {                                 // Returns the data stored in the top element on the stack.
    return list->getHeadData();
} 

template<typename T>
bool LStack<T>::isEmpty() {                                 // Checks if the stack is empty, returns false if any element exists.
	if (list->getSize() > 0) {
		return false;
	}
	return true;	
}	

