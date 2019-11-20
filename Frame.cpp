//
// Created by Rob on 11/19/2019.
//



#include "Frame.hpp"

Frame::Frame(Board* brd) {
    for(int n = 0; n < 81; n++) {
        states[n] = brd->getSquare(n);
    }
}

State& Frame::operator[](int n) {
    return states[n];
}

ostream& Frame::print(ostream & out) {
    for(int sq_loc = 0; sq_loc < 81; ++sq_loc) {
        states[sq_loc].print(cout);
    }
    return out;
}


