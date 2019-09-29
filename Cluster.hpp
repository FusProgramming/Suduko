//
// Created by Rob on 9/28/2019.
//

#ifndef P2_SQUARE_CLUSTER_HPP
#define P2_SQUARE_CLUSTER_HPP

#include "Square.hpp"

class Cluster {
    public:
        Cluster(const char *, Square*[9]);
        void print();
        void shoop();
        
    private:
        const char* cType;
        Square* sArray[9];

};

inline ostream& operator<< (ostream& out, Cluster& cl) {
    cl.print();
    return out;
}

#endif //P2_SQUARE_CLUSTER_HPP
