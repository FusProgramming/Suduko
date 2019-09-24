// Robert Fus
// CSCI 6626 - Object-Orientated Principles & Practices
// Program 3: Board
// File: Board.cpp
// 9/21/2019

#include "Board.hpp"

//----------------------------------------------------------------
Board::Board(int n, ifstream &myFile)  {
    cout << "Board Constructing" << endl;
    fName.open("puz1.txt");
    if(!fName.is_open()) fatal("Error Opening File");
    getPuzzle();

}
//----------------------------------------------------------------
void Board::getPuzzle() {
    char ch;
    int sub =0;
    for(int j = 1; j < n; j++) {
        for(int k = 1; k < n; k++) {
            fName >>ch;
            if((ch > '0' && ch <= '9') || ch == left) {
                Square Sq(ch,j,k);
                brd[sub] = Sq;
                sub++;
            }

        }
    }
}
//----------------------------------------------------------------
Square& Board::sub(int j, int k) {
    int sub;
    sub = (j - 1) * 9 + (k + 1);
    return brd[sub];

}

Board::~Board() {
    cout << "Destructed Board" << endl;
}


void Board::print() {

    for(int j = 0; j <= 9; j++) {
        for(int k = 0; k <= 9; k++) {
            cout << brd[sub(j,k)] << endl;
        }

    }
}