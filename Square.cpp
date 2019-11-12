// Robert Fus
// CSCI 6626 - Object-Orientated Principles & Practices
// Program 3: Game
// File: Square.cpp
// 9/12/2019

#include "Square.hpp"
#include "Cluster.hpp"

//----------------------------------------------------------------
State::State(char c) {
    value = c;
    if(c >= '1' && c <= '9') {
        possList = 0;
        fixed = true;
    } else if(c == '-') {
        possList= 0x3fe;
        fixed = false;
    }
}

//----------------------------------------------------------------
void State::mark(char ch) {
    int val = ch - '0';
    bool markValue = (possList >> val) & 1;
    if(fixed) {
        cerr << "THIS IS FIXED, VALUE WILL NOT CHANGE. " << endl;
    } else {
        if(markValue) {
            value = ch;
            possList = 0;
        } else {
            cerr << "Not Valid Possibility" << endl;
        }
    }
}

//----------------------------------------------------------------
ostream& State::print(ostream& out) {
    short printList, printMask;
    cout << "Value: " << value;
    cout << " Possibility: ";
    for(int k = 1; k <= 9; k++) {
        printList = possList ;
        printMask = 1 << k;
        if((printList & printMask) == 0) {
            out << '-';
        } else {
            out << k;
        }
    }
    return out;
}

//----------------------------------------------------------------
Square::Square(char c, short int row, short int col) : State(c), row(row), col(col) {
    cout << "Square: [" << row << ", " << col << "] Constructed " ;
}

//----------------------------------------------------------------
Square::~Square() {
    cout << " Deleting Square: [" << row << ", " << col << "]" << endl;
}

//----------------------------------------------------------------
void Square::mark(char ch) {
    State::mark(ch);
    for(Cluster * cluster : clues) {
        cluster->shoop(value);
    }
}
//----------------------------------------------------------------
void Square::addCluster(Cluster* pCl) {
    clues.push_back(pCl);
}

//----------------------------------------------------------------
void Square::turnOff(int n) {
    short mask = 1 << n;
    possList = possList & ~mask;
}
//----------------------------------------------------------------
ostream& Square::print(ostream& out) {
    out << "Square: [" << row << ", " << col << "] ";
    State::print(out);
    return out;
}
