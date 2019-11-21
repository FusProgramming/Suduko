//
// Created by Rob on 11/19/2019.
//



#include "Frame.hpp"
//----------------------------------------------------------------
Frame::Frame(Board* brd) {
    for(int n = 0; n < 81; n++) {
        states[n] = brd->getSquare(n);
    }
}
//----------------------------------------------------------------
State& Frame::operator[](int n) {
    return states[n];
}

void Frame::serialize(ostream &out) {
    out.write((char *)&states, sizeof(states));
}

void Frame::realize(ifstream &in) {
    in.read((char *)&states, sizeof(states));
}



