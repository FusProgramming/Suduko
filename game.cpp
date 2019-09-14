// Robert Fus
// CSCI 6626 - Object-Orientated Principles & Practices
// Program 3: Game
// File: Square.cpp
// 9/12/2019

#include "game.hpp"

int menuComponent(void);
//----------------------------------------------------------------
const char* menu_c[] = {
        "1.",
        "2.",
        "3.",
        "4.",
        "5.",
        "6.",

};

//----------------------------------------------------------------
int game() {
    int selection;
    do {
        selection = menu_c();
        switch(selection) {
            case 1: break;
            case 2: break;
            case 3: break;
            case 4: break;
            case 5: break;
            case 6: break;
            case 7: break;
        }
    } while(selection != 7);

}

//----------------------------------------------------------------
