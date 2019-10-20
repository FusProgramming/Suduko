// Robert Fus
// CSCI 6626 - Object-Orientated Principles & Practices
// Program 3: Game
// File: Square.cpp
// 9/12/2019

#include "game.hpp"

//----------------------------------------------------------------
game::game(const string& strm) {
    char x;
    const string legal = "TtDdSs";
    fName.open( strm);
    if(!fName.is_open()) { fatal("Error, File will not open"); }
    fName >> x;
    size_t validGame = legal.find(x);
    if(validGame!=string::npos) {
        gType = x;
        cout << gType;
        newGame(strm);
    } else {
        fatal("Invalid Type in the Game");
    }
    cout << "CLOSING" << endl;
    fName.close();
}
//----------------------------------------------------------------
game::~game() {
    delete brd;
    cout << "Board Deleted" << endl;
}
//----------------------------------------------------------------
void game::newGame(const string& strm) {
    if(gType =='t') {
        gSize= 9;
    } else if(gType == 'd') {
        cerr << "Empty else Statement" << endl;
        fatal("Empty statement");
    } else if(gType == 's'){
        gSize= 6;
    }
    brd = new Board(gSize, fName);
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

//----------------------------------------------------------------
ostream& game::print(ostream& out) {
    out << *brd;
    return out;
}
