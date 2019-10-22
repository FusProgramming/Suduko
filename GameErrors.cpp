// Robert Fus
// CSCI 6626 - Object-Orientated Principles & Practices
// Program 6: Exceptions
// File: GameErrors.cpp
// 10/22/2019
#include "GameErrors.hpp"
//----------------------------------------------------------------
GameErrors::GameErrors(int row, int col, char value) : r(row), c(col), val(value) {
    cerr << "Game Error Indicated" << endl;
}

//----------------------------------------------------------------
void GameErrors::print() {
    cerr << "Game Error: Bad Input" << endl;
    cerr << "Input: [" << r << ", " << c << "] Value: " << val << endl;
}

//----------------------------------------------------------------
GameValues::GameValues(int row, int col, char ch) : GameErrors(r, c, val){
    cerr << "Game Value Error Indicated" << endl;
}

//----------------------------------------------------------------
void GameValues::print() {
    cerr << "Incorrect Value" << endl;
    cerr << "Input: [" << r << ", " << c << "] Value: " << val << endl;
}