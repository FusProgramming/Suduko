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
            case 'Q':
            case 'q':
                bye();
                exit(0);
            case 'M':
            case 'm':
                for (;;) {
                    try {
                        char row, col, ch;
                        cout << "What is the row you want to mark?" << endl;
                        cin >> row;
                        cout << "What is the column you want to mark?" << endl;
                        cin >> col;
                        cout << "What number do you want to input?" << endl;
                        cin >> ch;
                        if ((row >= '1' && row <= '9') && (col >= '1' && col <= '9')) {
                            break;
                        } else {
                            throw GameValues(row, col, ch);
                        }
                    } catch (GameErrors ex) {
                        ex.print();
                    } catch (GameValues ex) {
                        ex.print();
                    }
                    break;
                }
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
                cout << "Enter a Valid Input" << endl;
                break;
        }
    }
}


//----------------------------------------------------------------
ostream& game::print(ostream& out) {
    out << *brd;
    return out;
}
