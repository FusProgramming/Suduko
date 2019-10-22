// Robert Fus
// CSCI 6626 - Object-Orientated Principles & Practices
// Program 6: Exceptions
// File: StreamErrors.hpp
// 10/22/2019

#ifndef P2_SQUARE_STREAMERRORS_HPP
#define P2_SQUARE_STREAMERRORS_HPP

#include "tools.hpp"

class StreamErrors {
    public:
        ifstream& fName;
        StreamErrors(ifstream& strm);
        virtual void print();
};
class StreamFiles : public StreamErrors {
    public:
        StreamFiles(ifstream& strm);
        virtual void print();
};

//----------------------------------------------------------------
class StreamBoard : public StreamErrors {
    public:
        StreamBoard(ifstream& strm);
        virtual void print();
};

#endif //P2_SQUARE_STREAMERRORS_HPP
