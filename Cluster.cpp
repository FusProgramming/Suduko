// Robert Fus
// CSCI 6626 - Object-Orientated Principles & Practices
// Program 5: Cluster
// File: Cluster.cpp
// 10/15/2019

#include "Cluster.hpp"

const char* Cluster::clusterName[] = { "row", "col" , "box", "diag"};
//----------------------------------------------------------------
Cluster::Cluster(ClusterT type, Square * s[]){
    cout << "7" << endl;
    cType = type;
    cout << "8" << endl;
    for(int j = 0 ; j < 6; j++) {
        cout << "9" << endl;
        sArr[j] = s[j];
        cout << "10" << endl;
        s[j]->addCluster(this);
        cout << "11" << endl;

    }
    cout << "12" << endl;

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

