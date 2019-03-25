#ifndef A3_STACK_H_
#define A3_STACK_H_

#include <vector>

/**
 *  \brief Generic class representing a stack of type T
 *  \details Internal storage of data done using the std vector library
 */
template <class T>
class Stack {
    private:
        /// The vector of type T
        std::vector<T> s;

    public:

        /**
         *  \brief  Constructs a new stack
        Stack(std::vector<T> s);
        Stack();
        Stack<T> push(T a);
        Stack<T> pop ();
        T top();
        unsigned int size();
        std::vector<T> toSeq();
};

#endif
