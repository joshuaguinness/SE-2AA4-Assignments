// Implementation here

#include "../include/Stack.h"
#include "../include/CardTypes.h"
#include <exception>
#include <stdexcept>
#include <iostream>
#include <algorithm>

using std::vector;

// Public Methods
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

int main()
{

//std::vector<CardT> v = {7, 5, 16, 8};



  std::vector<CardT> d;
  for (RankT rank = ACE; rank <= KING; rank++) {
    for (unsigned int suit = 0; suit < 4; suit++) {
      CardT n = { static_cast<SuitT>(suit), rank };
      d.push_back(n);
      d.push_back(n);
    }
  }
  std::random_shuffle(d.begin(), d.end());

  
/*
  std::cout << "Sequence length: " << d.size() << std::endl;
  std::cout << "Deck size: " << d.size() << std::endl;
  std::cout << "Deck top: " << d.top().s << " " << d.top().r << std::endl;
/*
CardStackT foo(vec);
  foo = foo.push(d[0]);
  CardT bar = foo.top();
  std::cout << "Card: " << bar.s << " " << bar.r << std::endl;
  foo = foo.pop();
*/
    return 0;
}