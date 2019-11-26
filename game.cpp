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
        brd = new TradBoard(gSize, fName, 27);

    } else if(gType == 'd') {
        gSize = 9;
        brd = new DiagBoard(gSize,fName);
    } else if(gType == 's'){
        gSize= 6;
        brd = new SixyBoard(gSize, fName);
    }
}
//----------------------------------------------------------------
void game::run() {
    for (;;) {
        if(gType == 's') {
            Viewer fancyView(6,6, *brd);
            fancyView.show(cout);
        } else {
            Viewer fancyView(9,9, *brd);
            fancyView.show(cout);
        }

        char c = menu_c("Menu", 6, menu, menuX);
        switch (c) {
            case '6':
                bye();
                exit(0);
            case '1':
                for (;;) {
                    brd->mark();
                    Frame* frame = new Frame(brd);
                    undoMark.push(frame);
                    redoMark.zap();
                    break;
                }
                break;
            case '2':
                cout << "UNDO IMPLEMENTED" << endl;
                undo();
                break;
            case '3':
                cout << "\t\tREDO IMPLEMENTED" << endl << endl;
                redo();

                break;
            case '4':
                save();
                cout << "File Saved" << endl;
                break;
            case '5':
                load();
                cout << "File Loaded" << endl;

                break;
            default:
                cout << "Enter a Valid Input" << endl;
                break;
        }
    }
}


//----------------------------------------------------------------
void game::undo() {
    if (undoMark.size() >= 2) {
        redoMark.push(undoMark.top());
        undoMark.pop();
        brd->restoreState(undoMark.top());
    }
}
//----------------------------------------------------------------
void game::redo() {
    if (redoMark.size() > 0) {
        brd->restoreState(redoMark.top());
        undoMark.push(redoMark.top());
        redoMark.pop();
    }
}

//----------------------------------------------------------------
ostream& game::print(ostream& out) {
    out << *brd;
    return out;
}

//----------------------------------------------------------------
void game::save() {
    try {
        string fileName;
        cout << "File Name: ";
        cin >> fileName;
        Frame *top = undoMark.top();
        ofstream out(fileName);
        top->serialize(out);
        out.close();
    } catch (StreamErrors &e) {

}
}
//----------------------------------------------------------------
void game::load() {
    try {
        string fileName;
        cout << "File Name:";
        cin >> fileName;
        ifstream input(fileName);
        undoMark.zap();
        redoMark.zap();
        Frame* frame = new Frame(brd);
        undoMark.push(frame);
        undoMark.top()->realize(input);
        brd->restoreState(undoMark.top());
    } catch(StreamErrors& e) {
        e.print();
    }

}
