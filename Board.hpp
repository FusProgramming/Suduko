// Robert Fus
// CSCI 6626 - Object-Orientated Principles & Practices
// Program 3: Board
// File: Board.hpp
// 9/21/2019

#ifndef P2_SQUARE_BOARD_HPP
#define P2_SQUARE_BOARD_HPP

#include "tools.hpp"
#include "Square.hpp"

#define nSq (9 * 9)

class Board {
public:
    Board(ifstream& myFile);
    void getPuzzle();
    Square& sub(int j, int k);
    ~Board();
    void print();
private:
    int n = 9;
    Square brd[81];
    ifstream fName;
    short int left = '-';

};

inline ostream& operator<< (ostream& out, Board& b) {
    b.print();
    return out;
}

#endif //P2_SQUARE_BOARD_HPP
