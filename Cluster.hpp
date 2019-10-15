//
// Created by Rob on 9/28/2019.
//

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
