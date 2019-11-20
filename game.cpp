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
    fName.open(strm);
    if(!fName.is_open()) {
        throw StreamErrors((ifstream&) strm);
    }
    fName >> x;
    size_t validGame = legal.find(x);
    if(validGame!=string::npos) {
        gType = x;
        cout << gType;
        newGame(strm);
    } else {
        throw StreamFiles((ifstream&) strm);
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
        brd = new Board(gSize, fName, 27);
    } else if(gType == 'd') {
        gSize = 9;
        brd = new DiagBoard(gSize,fName);
    } else if(gType == 's'){
        gSize= 6;
    }
}
//----------------------------------------------------------------
void game::run() {
    for (;;) {
        Viewer fancyView(9,9, *brd);
        fancyView.show(cout);
        char c = menu_c("Menu", 6, menu, menuX);
        switch (c) {
            case '6':
                bye();
                exit(0);
            case '1':

                for (;;) {
                    brd->mark();
                    Frame* frame = new Frame(brd);
                    undo.push(frame);
                    redo.zap();
                    break;
                }
                break;
            case '2':
                cout << "1" << endl;
                undo_move();
                cout << "1" << endl;
                break;
            case '3':
                cout << "1" << endl;
                redo_move();
                cout << "1" << endl;
                break;
            case '4':
                cout << "Restore - Unfinished" << endl;
                break;
            case '5':
                break;
            default:
                cout << "Enter a Valid Input" << endl;
                break;
        }
    }
}


//-------------------------------------------------------------------------
void game::undo_move() {
    cout << "1" << endl;
    if (undo.size() >= 2) {
        cout << "1" << endl;
        redo.push(undo.top());
        undo.pop();cout << "1" << endl;
        brd->restoreState(undo.top());cout << "1" << endl;
    }
}
//-------------------------------------------------------------------------
void game::redo_move() {
    if (redo.size() > 0) {

        cout << "1" << endl;
        brd->restoreState(redo.top());
        cout << "1" << endl;
        undo.push(redo.top());
        cout << "1" << endl;
        redo.pop();
        cout << "1" << endl;
    }
}

//----------------------------------------------------------------
ostream& game::print(ostream& out) {
    out << *brd;
    return out;
}
