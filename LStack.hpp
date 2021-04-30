

#ifndef LSTACK_H
#define LSTACK_H
#include <iostream>
#include "LinkedList.hpp"

using namespace std;

template<typename T>
class LStack 
{
    public:

        LStack() {
            list = new LinkedList<T>;
        }  

        LStack(T& data) {
            list = new LinkedList<T>(data);
        }

        ~LStack() {
            delete list;
        }

        void push(T data) {
            list->addToHead(data);
        }

        T pop() {
            return list->removeFromHead();
        }

        T peek() {
            return list->getHeadData();
        } 

        int size() {
            return list->getSize();
        }

    private:
        LinkedList<T>* list;
};
template<typename T>
ostream& operator << (ostream& output, LStack<T>& list) {                                       
	int size = list.size();
    LStack<T> tempStack;
	for (int i=0; i < size; i++) {
		output << list.peek() << "\n";
		tempStack.push(list.pop());
    }
    for (int i=0; i < size; i++) {
        list.push(tempStack.pop());
    }
	return output;                                          // Returns the output. 
}
#endif