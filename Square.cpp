// Robert Fus
// CSCI 6626 - Object-Orientated Principles & Practices
// Program 3: Game
// File: Square.cpp
// 9/12/2019

#include "Square.hpp"

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
    if(fixed) {
        cout << "THIS IS FIXED, VALUE WILL NOT CHANGE. " << endl;
    } else {
        value = ch;
        possList = 0;
    }
}

//----------------------------------------------------------------
void State::print() {
    short printList, printMask;
    cout << "Value: " << value;
    cout << " Possibility: ";
    for(int k = 1; k < 9; k++) {
        printList = possList >> 1;
        printMask = 1 << k;
        if((printList & printMask) == 0) {
            cout << '-';
        } else {
            cout << k;
        }
    }
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
    cout << "Enter Value" << endl;
    cin >> ch;
    if(ch < '1' && ch > '9') {
        cout <<"Please choose another value" << endl;
        cin >> ch;
    }
    cout << "PossList Before: " << possList << endl;
    State::mark(ch);
    cout << "PossList After: " << possList << endl;
}
//----------------------------------------------------------------
void Square::addCluster() {

}
//----------------------------------------------------------------
ostream& Square::print(ostream& out) {
    out << "Square: [" << row << ", " << col << "] ";
    State::print();
    return out;
}
