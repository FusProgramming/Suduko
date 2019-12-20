// Robert Fus
// CSCI 6626 - Object-Orientated Principles & Practices
// Program 9: Undo/Redo
// File: Frame.hpp
// 11/18/2019


#ifndef P2_SQUARE_FRAME_HPP
#define P2_SQUARE_FRAME_HPP

#include "Board.hpp"
#include "tools.hpp"
#include "Square.hpp"
class Board;
class Frame {
public:
    Frame() = default;
    Frame(Board *brd);
    ~Frame() = default;
    State* getState() { return states;}
    State states[81];
    State& operator [] (int n); //SubScript operator to access elemtns in array style
    void serialize(ostream& out);
    void realize(ifstream& in);
};



#endif //P2_SQUARE_FRAME_HPP
