// Robert Fus
// CSCI 6626 - Object-Orientated Principles & Practices
// Program 5: Cluster
// File: Cluster.cpp
// 10/15/2019

#include "Cluster.hpp"

const char* Cluster::clusterName[] = { "row", "col" , "box" };
//----------------------------------------------------------------
Cluster::Cluster(ClusterT type, Square * s[9]) {
    cType = type;
    for(int j = 0 ; j < 9; j++) {
        sArr[j] = s[j];
        s[j]->addCluster(this);
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

