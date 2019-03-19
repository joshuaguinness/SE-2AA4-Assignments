#ifndef A3_STACK_H_
#define A3_STACK_H_

#include <vector>
using namespace std;

template <typename T>
class StackT {
    private:
        std::vector<T> s;

    protected:

    public:
        template <class T>
        Stack<T> Stack (std::vector<T> s);

        Stack<T> push(T a);

        Stack<T> pop ();

        T top();

        unsigned int size();

        std::vector<T> toSeq();

};

#endif
