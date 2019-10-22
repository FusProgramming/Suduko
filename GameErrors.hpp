// Robert Fus
// CSCI 6626 - Object-Orientated Principles & Practices
// Program 6: Exceptions
// File: GameErrors.hpp
// 10/22/2019

#ifndef P2_SQUARE_GAMEERRORS_HPP
#define P2_SQUARE_GAMEERRORS_HPP

#include "tools.hpp"

class GameErrors {
    public:
        int j, k;
        char val;
        GameErrors(int row, int col, char value);
        virtual void print();
};

class GameValues : public GameErrors {
    public:
        GameValues(int row, int col, char ch);
        virtual void print();
};

#endif //P2_SQUARE_GAMEERRORS_HPP
