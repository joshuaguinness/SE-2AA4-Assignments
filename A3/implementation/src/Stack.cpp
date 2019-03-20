// Implementation here

#include "../include/Stack.h"

using std::vector;

/*
private:
        std::vector<T> s;

    public:
        Stack (std::vector<T> s);
        Stack<T> push(T a);
        Stack<T> pop ();
        T top();
        unsigned int size();
        std::vector<T> toSeq();
*/

// Public Methods
template <class T>   // Need this in front of every method   
StackT<T>::Stack(std::vector<T> s)
{

}

template <class T>
Stack<T> Stack<T>::push(T a)
{

}

template <class T>
Stack<T> Stack<T>::pop()
{

}

template <class T>
T Stack<T>::top()
{

}

template <class T>
unsigned int Stack<T>::size()
{

}

template <class T>
std::vector<T> Stack<T>::toSeq()
{
    
}

// Private Methods

// Explicit instatiations of Stack
template class Stack<CardT>;

// Keep this at bottom

