// Robert Fus
// CSCI 6626 - Object-Orientated Principles & Practices
// Program 3: Game
// File: Square.cpp
// 9/12/2019

#ifndef P2_SQUARE_GAME_HPP
#define P2_SQUARE_GAME_HPP

#include "tools.hpp"
#include "Board.hpp"

class game {
    public:
        game(const char * );
        void run();
    private:
        ifstream fName;
        Board* brd;
        int gSize;
        char gType;
        const char * menu[6] = {
            "1. Mark", "2. Undo", "3. Redo", "4. Save Game", "5. Restore Game", "6. Quit"
        };
        const char * menuX = "MmUuRrSsTtQq";

};

#endif //P2_SQUARE_GAME_HPP
