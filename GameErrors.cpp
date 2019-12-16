// Robert Fus
// CSCI 6626 - Object-Orientated Principles & Practices
// Program 6: Exceptions
// File: GameErrors.cpp
// 10/22/2019

#include "GameErrors.hpp"

//----------------------------------------------------------------
GameErrors::GameErrors(int row, int col, char value) : j(row), k(col), val(value) {
    cerr << "Game Error Indicated" << endl;
}

//----------------------------------------------------------------
void GameErrors::print() {
    cerr << "Game Error: Bad Input" << endl;
    cerr << "Input: [" << j << ", " << k << "] Value: " << val << endl;
}

//----------------------------------------------------------------
GameValues::GameValues(int row, int col, char ch) : GameErrors(j, k, val){
    cerr << "Game Value Error Indicated" << endl;
    cerr << "Input: ["<< row << ", " << col << "] Value: " << ch << endl;
}

//----------------------------------------------------------------
void GameValues::print() {
    cerr << "Incorrect Value: Out of Scope " << endl;
}