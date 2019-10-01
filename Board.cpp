// Robert Fus
// CSCI 6626 - Object-Orientated Principles & Practices
// Program 3: Board
// File: Board.cpp
// 9/21/2019

#include "Board.hpp"
#include "Cluster.hpp"

//----------------------------------------------------------------
Board::Board(int n, const char* myFile) : N(n)  {
    cout << "Board Constructing" << endl;
    fName.open(myFile);
    if(!fName.is_open()) fatal("Error Opening File");
    getPuzzle(n);
}

//----------------------------------------------------------------
void Board::getPuzzle(int n) {
    char ch;
    brd = new Square[n * n];
    for (int j = 1; j <= n; j++) {
        for (int k = 1; k <= n; k++) {
            fName >> ch;
            if ((ch >= '1' && ch <= '9') || ch == left) {
                Square Sq(ch, j, k);
                sub(j, k) = Sq;
            }
            if (k == 9) cout << "\n";
            if (k == 10 && ch != '\n') fatal("Error, Oversized File");
            if (j == 10 && !fName.eof()) fatal("Error, Oversized File");

        }
    }
    makeClusters();
}

//----------------------------------------------------------------
Square& Board::sub(int j, int k) {
    int sub = (j - 1) * 9 + (k - 1);
    return brd[sub];
}
//----------------------------------------------------------------
void Board::makeClusters() {
    //Creates Clusters of Rows
    for(int sub = 0; sub < 81; sub+=9){
        Square* rows[9];
        for(int n = 0; n < 9; n++){
            rows[n] = &brd[sub + n];
        }
        clusters.push_back(new Cluster("row", rows));

    }
    //Creates Clusters of Columns
    for(int n = 0; n < 9; n++){
        Square* cols[9];
        for(int sub = 0; sub < 81; sub+=9){
            cols[sub/9] = &brd[n + sub];
        }
        clusters.push_back(new Cluster("col", cols));
    }
    //TODO:Create cluster of boxes
    for(int n = 0; n <= 54; n+=27){
        for(int k = n; k <= n+6; k+=3){
            Square* box[9];
            int sub = 0;
            for(int row = k; row <= k + 20; row+=9){
                for(int cell = 0; cell < 3; cell++){
                    box[sub] = &brd[row + cell];
                    sub++;
                }
            }
            clusters.push_back( new Cluster("BOX", box));
        }
    }
}
//----------------------------------------------------------------
void Board::createRow() {
}
//----------------------------------------------------------------
void Board::createColumn() {

}
//----------------------------------------------------------------
void Board::createBox() {

}

//----------------------------------------------------------------
Board::~Board() {
    delete[] brd;
    cout << "Destructed Board" <<  endl;
}

//----------------------------------------------------------------
void Board::print() {
    for(int n = 0; n < 81; n++){
        cout << brd[n];
    }
}
void Board::printCluster(ostream& out) {
    for (Cluster* cl : clusters) {
        cout << endl;
        out << *cl << endl;
    }
}