// Robert Fus
// CSCI 6626 - Object-Orientated Principles & Practices
// Program 3: Game
// File: Square.cpp
// 9/12/2019

#include "Square.hpp"
#include "game.hpp"

void testState();
void testSquare();

//----------------------------------------------------------------
int main(int argc, const char * argv[]) {
    banner();
    string myFile = "puz2.txt";
    game game(myFile.c_str());
    game.run();
    testState();
    testSquare();
}

//----------------------------------------------------------------
void testState() {
    State testFixed('1');
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
    Square testSq('1', 0,0);
    cout << testSq << endl;
    testSq.mark('2');
    Square testSq2('-', 3,2);
    cout << testSq2 << endl;
    testSq2.mark('3');
    cout << "Value changed to three. " << testSq2 << endl;
    Square testSq3('-',3,2);
    cout << testSq3 << endl;
    testSq3.mark('-');
    cout << testSq3 << endl;

}