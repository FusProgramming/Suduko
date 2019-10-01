// Robert Fus
// CSCI 6626 - Object-Orientated Principles & Practices
// Program 3: Board
// File: Board.hpp
// 9/21/2019

#ifndef P2_SQUARE_BOARD_HPP
#define P2_SQUARE_BOARD_HPP

#include "tools.hpp"
#include "Square.hpp"

enum ClusterT {
    row, col, box
};

class Board {
    public:
        Board(int n, const char* myFile);
        ~Board();
        Square& sub(int j, int k);
        void print();
        void printCluster(ostream&);
    private:
        int N;
        Square* brd;
        void getPuzzle(int n);
        ifstream fName;
        short int left = '-';
        vector<Cluster*> clusters;
        void makeClusters();
        void createRow();
        void createColumn();
        void createBox();



};

inline ostream& operator<< (ostream& out, Board& b) {
    b.print();
    return out;
}

#endif //P2_SQUARE_BOARD_HPP
