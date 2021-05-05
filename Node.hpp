
//*********************************************************************************************//
//  Class Node (implementation)                                                                //
//  Author: Mick Wiedermann                                                                    //
//  Course: SENG1120 | Assignment 2                                                            //
//  Date  : 2021-05-01                                                                         //
//  Program Description: Implementation file for the Node Object.                              //
//***********************************************************************************************


////////// CONSTRUCTORS ///////////////////////////
template <typename T>
Node<T>::Node()
{
    next = NULL;
    previous = NULL;
}

template <typename T>
Node<T>::Node(const T& initData, Node* initNext, Node* initPrevious)
{
    data = initData;
    next = initNext;
    previous = initPrevious;
}
////////// DESTRUCTOR ///////////////////////////

template <typename T>
Node<T>::~Node() 
{
    next = NULL;
    previous = NULL;
}

////////// MUTATOR FUNCTIONS (SETTERS) //////////

template <typename T>
void Node<T>::setData(const T& newData)  
{
    data = newData;
}

template <typename T>
void Node<T>::setNext (Node* nextLink)               
{
    next = nextLink;
}   

template <typename T>           
void Node<T>::setPrevious (Node* previousLink)       
{
    previous = previousLink;
}  

////////// ACCESSOR FUNCTIONS (GETTERS) /////////

template <typename T> 
const T Node<T>::getData() const
{
    return data;
}

template <typename T>
const Node<T>* Node<T>::getNext() const                 
{
    return next;
}

template <typename T>               
Node<T>* Node<T>::getNext()                             
{
    return next;
} 

template <typename T>
const Node<T>* Node<T>::getPrevious() const             
{
    return previous;
} 

template <typename T>
Node<T>* Node<T>::getPrevious()                         
{
    return previous;
} 