// Robert Fus
// CSCI 6626 - Object-Orientated Principles & Practices
// Program 3: Game
// File: Square.cpp
// 9/12/2019

#include "Square.hpp"
#include "game.hpp"
#include "Board.hpp"
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
            } catch ( StreamErrors ex) {
                ex.print();
            } catch ( StreamFiles ex) {
                ex.print();
            } catch ( StreamBoard ex) {
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
void testCluster() {
    Square* rows[9];
    int count = 0;
    cout << "BUILDING ROW" << endl;
    for (char ch = 1; ch <= 9; ch++) {
        rows[count++] = new Square('-', 1, ch);
        cout << endl;
    }
    Cluster cluster(row,rows);
    cout << cluster << endl;
    rows[3]->mark('5');
    cout << cluster << endl;
    rows[7]->mark('2');
    cout << cluster << endl;
}