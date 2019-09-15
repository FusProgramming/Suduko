// Robert Fus
// CSCI 6626 - Object-Orientated Principles & Practices
// Program 3: Game
// File: Square.cpp
// 9/12/2019

#ifndef P2_SQUARE_GAME_HPP
#define P2_SQUARE_GAME_HPP

#include "tools.hpp"

class game {
    public:
        game(const char *myFile);
        void run();
    private:
        //Board* brd;
        int gSize{};
        char gType{};
        ifstream myFile;
        const char * menu[6] = {
            "Mark", "Undo", "Redo", "Save Game", "Restore Game", "Quit"
        };

};


#endif //P2_SQUARE_GAME_HPP
