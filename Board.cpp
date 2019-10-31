// Robert Fus
// CSCI 6626 - Object-Orientated Principles & Practices
// Program 3: Board
// File: Board.cpp
// 9/21/2019

#include "Board.hpp"

static const char* clusterName[3];

//----------------------------------------------------------------
Board::Board(int n, ifstream& strm, int nType) throw (StreamErrors, GameErrors) : N(n), data(strm) {
    cout << "Board Constructing" << endl;
    if(!data.is_open()) {
        throw StreamFiles(strm);
    }
    getPuzzle(n, strm);
}

//----------------------------------------------------------------
Board::~Board() {
    delete[] brd;
    cout << "Destructed Board" <<  endl;
}

//----------------------------------------------------------------
void Board::getPuzzle(int n, ifstream& strm) {
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
        if (j == 10 && !data.eof()) throw StreamFiles(strm);
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
    for(j = 1; j <= N;j++) {
        createRow(j);
    }
    for(k = 1; k <= N; k++) {
        createColumn(k);
    }
    for(j = 1; j <= N; j+=3){
        for(k = 1; k <= N; k+=3){
            createBox(j, k);
        }
    }
}

//----------------------------------------------------------------
void Board::createRow(short j) {
    Square *rows[9];
    for(short p = j; p<= j ; p++) {
        for(short q = 1; q<= N; q++) {
            rows[q-1] = &sub(p,q);
        }
        clusters.push_back(new Cluster(row, rows));
    }
}

//----------------------------------------------------------------
void Board::createColumn(short k) {
    Square *cols[9];
    for(short q = k; q <= k; q++) {
        for(short p =1; p <= N; p++) {
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
    Cluster* clust = new Cluster(box, boxes);
    clusters.push_back(clust);
    for(int n = 0; n < N; n++) {
        boxes[n]->addCluster(clust);
        clust->shoop(boxes[n]->getValue());
    }
}

//----------------------------------------------------------------
ostream& Board::print(ostream& out) {
    for(int n = 0; n < N*N; n++){
        out << brd[n];
    }
    printCluster(out);
    return out;
}

//----------------------------------------------------------------
ostream& Board::printCluster(ostream& out) {
    for (Cluster* cl : clusters) {
        out << *cl << endl;
    }
    return out;
}

//----------------------------------------------------------------
DiagBoard::DiagBoard(int n, ifstream &strm) : Board(n, strm, 29) {
    DiagBoardOne();
    DiagBoardTwo();
}
//----------------------------------------------------------------
void DiagBoard::DiagBoardOne() {
    Square* diagOne[N];
    int count = 0;
    for(int sub = 0; sub < N*N; sub+=10){
        diagOne[count] = &brd[sub];
        count++;
    }
    clusters.push_back(new Cluster(diag, diagOne));
}

//----------------------------------------------------------------
void DiagBoard::DiagBoardTwo() {
    Square* diagTwo[N];
    int count = 0;
    for(int sub = 8; sub < N*N; sub+=8){
        diagTwo[count] = &brd[sub];
        count++;
    }
    clusters.push_back(new Cluster(diag, diagTwo));
}