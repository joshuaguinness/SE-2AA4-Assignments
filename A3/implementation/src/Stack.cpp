// Implementation here

#include "../include/Stack.h"
#include "../include/CardTypes.h"
#include <exception>
#include <stdexcept>
#include <iostream>
#include <algorithm>

//using std::vector;

// Public Methods

template <class T>
Stack<T>::Stack()
{
    std::vector<T> v;
    this->s = v;
}

template <class T>   // Need this in front of every method   
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
    // https://www.programiz.com/cpp-programming/if-else
    if (this->s.size() == 0)
    {
        throw std::out_of_range("Out of Range");
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