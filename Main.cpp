
#include <iostream>
#include <stdio.h> // To generate a random number
#include <cstdlib> // Provides access to the NULL pointer 
#include "LStack.h"
//#include "GameplayStack.h"

using namespace std;

// int fibo(int n) {
//             if (n==1 || n==2) {
//                 return 1;
//             }
//             return fibo(n-1) + fibo(n-2);
//         };

int main()
{   
    srand(time(0));                                               // Using current time as a seed for the random number generator
    LStack<int> stack1;
	LStack<string> stack2;

    for (int i = 0; i < 10; i++) {
        int x = rand();
        stack1.push(x);
    }
    
    stack2.push("Ok?? ");
    stack2.push("Test ");
    stack2.push("a" );
    stack2.push("is ");
    stack2.push("This ");
    
	cout << "\n" << endl;
	cout << "the Stack 1 height is: " << stack1.size() << "\n" << endl;
	
	cout << stack1 << endl; 
	
	cout << "Poping elements off stack 1" << endl;
	for (int i = 0; i < 5; i++) {
		stack1.pop();
	}
	
	cout << "the Stack 1 height is now: " << stack1.size() << "\n" << endl;

    cout << stack1 << endl; 

    cout << "the Stack 2 height is: " << stack2.size() << "\n" << endl;
	
	cout << stack2 << endl; 
	
	cout << "Poping elements off stack 2" << endl;
	for (int i = 0; i < 2; i++) {
		stack2.pop();
	}
	
	cout << "the Stack 2 height is now: " << stack2.size() << "\n" << endl;

    cout << stack2 << endl; 


    //cout << fibo(6) << endl;

    cout << " \n ** The program has finished ** \n" << endl;
    
    return 0;   
}
