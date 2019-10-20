// Robert Fus
// CSCI 6626 - Object-Orientated Principles & Practices
// Program 3: Game
// File: Square.cpp
// 9/12/2019

#include "Square.hpp"
#include "game.hpp"
#include "Board.hpp"
#include "Cluster.hpp"

void testState();
void testSquare();
void testBoard();
void testCluster();

//----------------------------------------------------------------
int main(int argc, const char * argv[]) {
    banner();
    testCluster();
    testBoard();
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
void testBoard() {
    game game("puz1.txt");
    game.print(cout);
    game.run();
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