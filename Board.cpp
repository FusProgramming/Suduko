// Robert Fus
// CSCI 6626 - Object-Orientated Principles & Practices
// Program 3: Board
// File: Board.cpp
// 9/21/2019

#include "Board.hpp"
#include "Cluster.hpp"

static const char* clusterName[3];

//----------------------------------------------------------------
Board::Board(int n, ifstream& strm) : N(n), data(strm)  {
    cout << "Board Constructing" << endl;
    if(!data.is_open()) fatal("Error Opening File");
    getPuzzle(n);
}

//----------------------------------------------------------------
Board::~Board() {
    delete[] brd;
    cout << "Destructed Board" <<  endl;
}

//----------------------------------------------------------------
void Board::getPuzzle(int n) {
    char ch;
    brd = new Square[n * n];
    for (int j = 1; j <= n; j++) {
        for (int k = 1; k <= n; k++) {
            data >> ch;
            if ((ch >= '1' && ch <= '9') || ch == left) {
                Square Sq(ch, j, k);
                sub(j, k) = Sq;
            }
            if (k == 9) cout << "\n";
        }
        if (j == 10 && !data.eof()) fatal("Error, Oversized File");
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
    short j, k;
    for(j = 1; j <= 9;j++) {
        createRow(j);
    }
    for(k = 1; k <= 9; k++) {
        createColumn(k);
    }
    for(j = 1; j <= 9; j+=3){
        for(k = 1; k <= 9; k+=3){
            createBox(j, k);
        }
    }
}

//----------------------------------------------------------------
void Board::createRow(short j) {
    Square *rows[9];
    for(short p = j; p<= j ; p++) {
        for(short q = 1; q<= 9; q++) {
            rows[q-1] = &sub(p,q);
        }
        clusters.push_back(new Cluster(row, rows));
    }
}

//----------------------------------------------------------------
void Board::createColumn(short k) {
    Square *cols[9];
    for(short q = k; q <= k; q++) {
        for(short p =1; p <= 9; p++) {
            cols[p-1] = &sub(p,q);
        }
    clusters.push_back(new Cluster(col, cols));
    }
}
//----------------------------------------------------------------
void Board::createBox(short j, short k) {
    Square* boxes[9];
    int count = 0;
    for(int row = j; row <= j + 2; row++){
        for(int cell = k; cell <= k + 2; cell++){
            boxes[count] = &sub(row,cell);
            count++;
        }
    }
    clusters.push_back(new Cluster(box, boxes));
}

//----------------------------------------------------------------
ostream& Board::print(ostream& out) {
    for(int n = 0; n < 81; n++){
        out << brd[n];
    }
    printCluster(out);
    return out;
}
ostream& Board::printCluster(ostream& out) {
    for (Cluster* cl : clusters) {
        out << *cl << endl;
    }
    return out;
}