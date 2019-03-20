// Implementation here

#include "../include/Stack.h"
#include <exception>

using std::vector;

// Public Methods
template <class T>   // Need this in front of every method   
StackT<T>::Stack(std::vector<T> s)
{
    this->s = s;
}

template <class T>
Stack<T> Stack<T>::push(T a)
{
    StackT<T> stack = StackT<T>(this->s.push_back(a));
    return stack;
}

template <class T>
Stack<T> Stack<T>::pop()
{
    if (this->s.size() == 0)
    {
        throw out_of_range();
    } else
    {
        StackT<T> stack = StackT<T>(this->s.pop_back());
        return stack;
    }
}

template <class T>
T Stack<T>::top()
{
    // https://www.programiz.com/cpp-programming/if-else
    if (this->s.size() == 0)
    {
        throw out_of_range();
    } else
    {
        return s.back();
    }
}

template <class T>
unsigned int Stack<T>::size()
{
    return this->s.size();
}

template <class T>
std::vector<T> Stack<T>::toSeq()
{
    return this->s;
}

// Private Methods

// Explicit instatiations of Stack
template class Stack<CardT>;

// Keep this at bottom

