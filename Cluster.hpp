// Robert Fus
// CSCI 6626 - Object-Orientated Principles & Practices
// Program 5: Cluster
// File: Cluster.hpp
// 10/15/2019

#ifndef P2_SQUARE_CLUSTER_HPP
#define P2_SQUARE_CLUSTER_HPP


#include "Board.hpp"
#include "Square.hpp"

enum ClusterT {
    row, col, box, diag, hBox, vBox
};
class Board;
class Cluster{
    public:
        Cluster(ClusterT type, Square* sq[], const int size);
        void print();
        void shoop(char val);
    private:
        vector<Square *> sArr;
        ClusterT cType;
        void addSquare(Square *sq);
        static const char* clusterName[];
        int size;
};

inline ostream& operator<< (ostream& out, Cluster& cl) {
    cl.print();
    return out;
}

#endif //P2_SQUARE_CLUSTER_HPP
