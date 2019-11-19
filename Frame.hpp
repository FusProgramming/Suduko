//
// Created by Rob on 11/19/2019.
//

#ifndef P2_SQUARE_FRAME_HPP
#define P2_SQUARE_FRAME_HPP

#include "Board.hpp"
#include "tools.hpp"
#include "Square.hpp"

class Frame {
public:
    Frame(Board* brd);
    ~Frame() = default;
    State* getState() { return states;}
    State states[81]{};
    State& operator [] (int n);

};

#endif //P2_SQUARE_FRAME_HPP
