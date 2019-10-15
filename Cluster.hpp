// Robert Fus
// CSCI 6626 - Object-Orientated Principles & Practices
// Program 5: Cluster
// File: Cluster.hpp
// 10/15/2019

#ifndef P2_SQUARE_CLUSTER_HPP
#define P2_SQUARE_CLUSTER_HPP

#include "Square.hpp"

enum ClusterT {
    row, col, box
};

class Cluster {
    public:
        Cluster(ClusterT, Square*[9]);
        void print();
        void shoop(char val);

    private:
        ClusterT cType;
        Square* sArr[9];
        static const char* clusterName[];

};

inline ostream& operator<< (ostream& out, Cluster& cl) {
    cl.print();
    return out;
}

#endif //P2_SQUARE_CLUSTER_HPP
