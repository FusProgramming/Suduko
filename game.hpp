// Robert Fus
// CSCI 6626 - Object-Orientated Principles & Practices
// Program 3: Game
// File: Square.cpp
// 9/12/2019

#ifndef P2_SQUARE_GAME_HPP
#define P2_SQUARE_GAME_HPP

#include "tools.hpp"
#include "Board.hpp"
#include "StreamErrors.hpp"
#include "GameErrors.hpp"
#include "Viewer.hpp"

class Board;
class game {
    public:
        game(const string& );
        ~game();
        void run();
        void newGame(const string&);
        ostream &print(ostream &out);
    private:
        ifstream fName;
        Board* brd;
        int gSize;
        char gType;
    void mark();

    const char * menu[6] = {
            "1. Mark", "2. Undo", "3. Redo", "4. Save Game", "5. Restore Game", "6. Quit"
        };
        const char * menuX = "MmUuRrSsTtQq";
};

inline ostream& operator<<(ostream& out, game& g) {
    return g.print(out);
}

#endif //P2_SQUARE_GAME_HPP
