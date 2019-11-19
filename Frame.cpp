//
// Created by Rob on 11/19/2019.
//



#include "Frame.hpp"



Frame::Frame(Board* brd) {
    for(int n = 0; n < 81; n++) {
    }
}

State& Frame::operator[](int n) {
    return states[n];
}


