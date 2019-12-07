// Robert Fus
// CSCI 6626 - Object-Orientated Principles & Practices
// Program 5: Cluster
// File: Cluster.cpp
// 10/15/2019

#include "Cluster.hpp"
#include "Board.hpp"

const char* Cluster::clusterName[] = { "row", "col" , "box", "diag", "hbox", "vbox"};

//----------------------------------------------------------------
Cluster::Cluster(ClusterT type, const vector<Square *>& sArr) {
    cType = type;
    for (Square *sq : sArr) {
        addSquare(sq);
        sq->addCluster(this);
    }
}

//----------------------------------------------------------------
void Cluster::shoop(char val) {
    int value = val - '0';
    for(Square* Sq : sArr) {
        Sq->turnOff(value);
    }
}

//----------------------------------------------------------------
void Cluster::print() {
    cout << clusterName[cType] << endl;
    for(Square* Sq : sArr) {
        Sq->print(cout);
        cout << endl;
    }
}

//----------------------------------------------------------------
void Cluster::addSquare(Square *sq) {
    sArr.push_back(sq);
}



