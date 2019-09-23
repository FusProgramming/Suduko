// Robert Fus
// CSCI 6626 - Object-Orientated Principles & Practices
// Program 3: Board
// File: Board.cpp
// 9/21/2019

#include "Board.hpp"

//----------------------------------------------------------------
Board::Board(ifstream& myFile) {
    cout << "Board Constructing" << endl;
    getPuzzle();

}
//----------------------------------------------------------------
void Board::getPuzzle() {
    char ch;
    int sub = 0;
    for(int j = 0; j < n; j++) {
        for(int k = 0; k < n ; k++) {
            fName >> ch;
            if((ch > '0' && ch < '10') || ch == left) {
                Square Sq(ch,j,k);
                brd[sub] = Sq;
                if(k == 9) {
                    ch = '\n';
                }
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
    for(int n = 0; n < 81; n++){
        if(n != 0 && n % 9 == 0) cout << '\n';
        cout << brd[n];
    }
}