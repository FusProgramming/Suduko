// Robert Fus
// CSCI 6626 - Object-Orientated Principles & Practices
// Program 3: Game
// File: Square.cpp
// 9/12/2019

#include "game.hpp"

//----------------------------------------------------------------
game::game(const char * myFile) {
    char x;
    string legal = "TtDdSs";
    fName.open(myFile);
    if(!fName.is_open()) { fatal("Error, File will not open"); }
    fName >> x;
    if(legal.find_first_of(x)==string::npos) {
        fatal("Invalid Type in the Game");
    } else if(legal.find_first_of(x)!=string::npos) {
        gType = x;
        cout << gType;
        newGame(myFile);
    }
}
//----------------------------------------------------------------
void game::newGame(const char* myFile) {
    if(gType =='t') {
        gSize= 9;
    } else if(gType == 'd') {
        cerr << "Empty else Statement" << endl;
        fatal("Empty statement");
    } else if(gType == 's'){
        gSize= 6;
    }
    brd = new Board(gSize, myFile);
}
//----------------------------------------------------------------
void game::run() {
    for(;;) {
        char c = menu_c("Menu", 6, menu, menuX);
        switch(c) {
            case 'Q':
            case 'q':
                bye();
                exit(0);
            case 'M':
            case 'm':
                cout << "Mark - Unfinished " << endl;
                break;
            case 'R':
            case 'r':
                cout << "Redo - Unfinished" << endl;
                break;
            case 'S':
            case 's':
                cout << "Save - Unfinished" << endl;
                break;
            case 'T':
            case 't':
                cout << "Restore - Unfinished" << endl;
                break;
            default:
                cout <<"Enter a Valid Input" << endl;
                break;
        }
    }
}



