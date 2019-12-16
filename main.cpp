// Robert Fus
// CSCI 6626 - Object-Orientated Principles & Practices
// Program 3: Game
// File: Square.cpp
// 9/12/2019

#include "Square.hpp"
#include "game.hpp"
#include "Cluster.hpp"
#include "StreamErrors.hpp"

void testState();
void testSquare();
void testBoard();
void testCluster();

//----------------------------------------------------------------
int main(int argc, const char * argv[]) {
    banner();
    for(;;) {
            try {
                string strm = "";
                cout << "What is the File Name?" << endl;
                cin >> strm ;
                game game(strm);
                game.print(cout);
                game.run();
            } catch ( StreamErrors& ex) {
                ex.print();
            }
    }
}

//----------------------------------------------------------------
void testState() {
    State testFixed('0');
    State testUnfixed('-');
    cout << "\n\tUnit Testing State" << endl
         << "----------------------------------------------------------------" << endl;
    cout << "Valid State Test: \n" << testFixed
         << "\n----------------------------------------------------------------" << endl;
    cout << "Invalid State Test:\n" <<  testUnfixed
         << "\n----------------------------------------------------------------" << endl;
    cout << "Test to mark value in fixed state:" << endl;
    testFixed.mark('8');
}

//----------------------------------------------------------------
void testSquare() {
    cout << "\n\tUnit Testing Square" << endl
         << "----------------------------------------------------------------" << endl;
    Square testSq('9', 1,1);
    cout << testSq << endl;
    testSq.mark('2');
    Square testSq2('-', 3,2);
    cout << testSq2 << endl;
    testSq2.mark('3');
    cout << "Value changed to three. " << testSq2 << endl;
}

//----------------------------------------------------------------