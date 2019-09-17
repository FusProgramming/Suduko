// Robert Fus
// CSCI 6626 - Object-Orientated Principles & Practices
// Program 3: Game
// File: Square.cpp
// 9/12/2019

#include "game.hpp"

//----------------------------------------------------------------
game::game(const char * myFile) {

    ifstream fName("puz2.txt");
    fName.open(myFile);
    if(!fName.is_open()) { fatal(" "); }
    string str;
    size_t found = str.find_first_of(menu2);
    while(found != string::npos) {
        str[found] = gType;
        found = str.find_first_of(menu2,found+1);
    }
}

//----------------------------------------------------------------
void game::run() {
    for(;;) {
        char c = menu_c("Menu", 6, menu, menu2);
        switch(c) {
            case 'Q':
                bye();
                exit(0);
            default:
                cout <<"Enter a Valid Input" << endl;
                break;

        }
    }

}



