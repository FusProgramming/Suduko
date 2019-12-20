// Robert Fus
// CSCI 6626 - Object-Orientated Principles & Practices
// Program 9: Undo/Redo
// File: Stack.hpp
// 11/18/2019


#ifndef P2_SQUARE_STACK_HPP
#define P2_SQUARE_STACK_HPP

#include "Frame.hpp"
#include "tools.hpp"

template<class T>
class Stack : public vector<T> {
    public:
        Stack() = default;
        ~Stack() = default;
        inline void pop() { vector<T>::pop_back();}
        inline Frame* top() { return vector<T>::back();}
        inline void push(Frame* frame) { vector<T>::push_back(frame); }
        inline int size() { return vector<T>::size();}
        inline void zap() {
            for(int n = size(); n > 0; n--) {
                pop();
            }
        }
};


#endif //P2_SQUARE_STACK_HPP
