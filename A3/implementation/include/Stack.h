/**
 * @file Stack.h
 * @author Joshua Guinness, guinnesj
 * @brief Module for a generic stack class
 * @version 0.1
 * @date 2019-03-26
 * 
 * @copyright Copyright (c) 2019
 * 
 */

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
         * \brief Constructs a new Stack object of type T
         * 
         * \param vector of type T
         */
        Stack(std::vector<T> s);

        /**
         * \brief Construct a new Stack object
         * 
         */
        Stack();

        /**
         * \brief Pushes a new object of type T onto the stack
         * 
         * \param object of type T
         * \return Stack<T> 
         */
        Stack<T> push(T a);

        /**
         * \brief Removes the top element of the stack
         * 
         * \return Stack<T> 
         */
        Stack<T> pop ();

        /**
         * \brief Gets the last element on the stack
         * 
         * \return object of type T
         */
        T top();

        /**
         * \brief Gets the number of elements on the stack
         * 
         * \return unsigned int representing the number of elements on the stack
         */
        unsigned int size();

        /**
         * \brief Converts the stack to a vector
         * 
         * \return std::vector<T> which represents the stack
         */
        std::vector<T> toSeq();
};

#endif
