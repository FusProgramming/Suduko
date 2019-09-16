// Robert Fus
// CSCI 6626 - Object-Orientated Principles & Practices
// Program 3: Game
// File: Square.cpp
// 9/12/2019

#include "game.hpp"

//----------------------------------------------------------------
game::game(const char * myFile) {

}

//----------------------------------------------------------------
void game::run() {
    for(;;) {
        char c = menu_c("Menu", 6, menu, menu2);
        switch(c) {
            case 1:
                cout << "Unfinished Section" << endl;
                break;
            case 2:
                cout << "Unfinished Section" << endl;
                break;
            case 3:
                cout << "Unfinished Section" << endl;
                break;
            case 4:
                cout << "Unfinished Section" << endl;
                break;
            case 5:
                cout << "Unfinished Section" << endl;
                break;
            case 6:
                exit(0);
                break;
            default:
                cout <<"Enter a Valid Input" << endl;
                break;

        }
    }

}

