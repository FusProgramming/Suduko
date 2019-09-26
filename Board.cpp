// Robert Fus
// CSCI 6626 - Object-Orientated Principles & Practices
// Program 3: Board
// File: Board.cpp
// 9/21/2019

#include "Board.hpp"

//----------------------------------------------------------------
Board::Board(int n, const char* myFile) : N(n)  {
    cout << "Board Constructing" << endl;
    fName.open(myFile);
    if(!fName.is_open()) fatal("Error Opening File");
    getPuzzle(n);
}

//----------------------------------------------------------------
void Board::getPuzzle(int n) {
    char ch;
    brd = new Square[n*n];
    for(int j = 1; j <= n; j++) {
        for(int k = 1; k <= n; k++) {
            fName >> ch;
            if((ch >= '1' && ch <= '9') || ch == left) {
                Square Sq(ch,j,k);
                sub(j,k) = Sq;
            }
            if(k==9) cout << "\n";
            if(k == 10 && ch != '\n') fatal("Error, Oversized File");
            if(j == 10 && !fName.eof()) fatal("Error, Oversized File");
        }
    }
}

//----------------------------------------------------------------
Square& Board::sub(int j, int k) {
    int sub = (j - 1) * 9 + (k - 1);
    return brd[sub];
}

//----------------------------------------------------------------
Board::~Board() {
    cout << "Destructed Board" << endl;
}

//----------------------------------------------------------------
void Board::print() {
    for(int n = 0; n < 81; n++){
        cout << brd[n];
    }
}