// Implementation here

#include "Stack.h"
#include "CardTypes.h"
#include <exception>
#include <stdexcept>
#include <iostream>
#include <algorithm>

// Public Methods
template <class T>
Stack<T>::Stack()
{
    this->s = std::vector<T>();
}

template <class T>
Stack<T>::Stack(std::vector<T> s)
{
    this->s = s;
}

template <class T>
Stack<T> Stack<T>::push(T a)
{
    this->s.push_back(a);
    Stack<T> stack = Stack<T>(this->s);
    return stack;
}

template <class T>
Stack<T> Stack<T>::pop()
{
    if (this->s.size() == 0)
    {
        throw std::out_of_range("Out of Range");
    } else
    {
        this->s.pop_back();
        Stack<T> stack = Stack<T>(this->s);
        return stack;
    }
}

template <class T>
T Stack<T>::top()
{
    // Got help from this website for the following lines of code:
    // https://www.programiz.com/cpp-programming/if-else
    if (this->s.size() == 0)
    {
        throw std::out_of_range("Out of Range");
    } else
    {
        return this->s.back();
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