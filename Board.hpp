// Robert Fus
// CSCI 6626 - Object-Orientated Principles & Practices
// Program 3: Board
// File: Board.hpp
// 9/21/2019

#ifndef P2_SQUARE_BOARD_HPP
#define P2_SQUARE_BOARD_HPP

#include "tools.hpp"
#include "Square.hpp"

class Board {
    public:
        Board(int n, ifstream& strm);
        ~Board();
        Square& sub(int j, int k);
        ostream& print(ostream& out);
        ostream& printCluster(ostream&);
        void makeClusters();
private:
        int N;
        Square* brd;
        void getPuzzle(int n);
        ifstream& fName;
        short int left = '-';
        vector<Cluster*> clusters;
        void createRow(short j);
        void createColumn(short k);
        void createBox(short j, short k);



};

inline ostream& operator<< (ostream& out, Board& b) {
    return b.print(out);
}

#endif //P2_SQUARE_BOARD_HPP
