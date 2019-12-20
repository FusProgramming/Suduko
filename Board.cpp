// Robert Fus
// CSCI 6626 - Object-Orientated Principles & Practices
// Program 3: Board
// File: Board.cpp
// 9/21/2019

#include "Board.hpp"

//----------------------------------------------------------------
Board::Board(int n, ifstream& strm, int nType) : N(n), data(strm) {
    cout << "Board Constructing" << endl;
    cout << n << endl;
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
    int sub = (j - 1) * N + (k - 1);
    return brd[sub];
}

//----------------------------------------------------------------
char Board::getMarkChar(int j, int k) const{
    int sub =(j- 1) * N + (k - 1);
    return brd[sub].getValue();
}

//----------------------------------------------------------------
string Board::getPossibilityString(int j, int k) const{
    string possListStr;
    short possList = brd[(j - 1) * N + (k - 1)].getPossList();
    for(int n = 1; n <= N; n++) {
        short mask = 1 << n;
        if((possList & mask) == 0) {
            possListStr.push_back('-');
        } else {
            possListStr.append(to_string(n));
        }
    }
    possListStr.push_back(' ');
    possListStr.push_back(' ');

    return possListStr;
}

//----------------------------------------------------------------
State Board::getSquare(int n) const {
    return brd[n];
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
}

//----------------------------------------------------------------
void Board::createRow(short j) {
    Square* rows[N];
    for(short p = j; p<= j ; p++) {
        for(short q = 1; q<= N; q++) {
            rows[q-1] = &sub(p,q);
        }
        clusters.push_back(new Cluster(row, rows, N));

    }
}

//----------------------------------------------------------------
void Board::createColumn(short k) {
    Square* cols[N];
    for(short q = k; q <= k; q++) {
        for(short p =1; p <= N; p++) {
            cols[p-1] = &sub(p,q);
        }
        clusters.push_back(new Cluster(col, cols, N));
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
void Board::mark() {
    short row, col;
    char ch;
    try {
        cout << "What is the row you want to mark?" << endl;
        cin >> row;
        cout << "What is the column you want to mark?" << endl;
        cin >> col;
        cout << sub(row, col);
        cout << "What number do you want to input?" << endl;
        cin >> ch;
        if(row < 1 || row > 9 || col < 1 || col > 9 ) {
            throw GameValues(row, col, ch);
        }
        sub(row, col).mark(ch);
        sub(row, col).getValue();
    } catch (GameValues& ex) {
        ex.print();
    }

}

//----------------------------------------------------------------
void Board::restoreState(Frame *frame) {
    State* states = frame->getState();
    for(int n = 0; n < N*N; n++ ) {
        (State&) brd[n] = states[n];
    }
}

//----------------------------------------------------------------
DiagBoard::DiagBoard(int n, ifstream &strm) : TradBoard(n, strm, 29) {
    DiagBoardClust();
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
    clusters.push_back(new Cluster(diag, diagOne, N));
}

//----------------------------------------------------------------
void DiagBoard::DiagBoardTwo() {
    Square* diagTwo[N];
    int count = 0;
    for(int sub = 8; sub < N*N; sub+=8){
        diagTwo[count] = &brd[sub];
        count++;
    }
    clusters.push_back(new Cluster(diag, diagTwo, N));
}

//----------------------------------------------------------------
void DiagBoard::DiagBoardClust() {
    short j,k;
    for(j = 1; j <= N; j+=3){
        for(k = 1; k <= N; k+=3){
            Square* boxes[N];
            int count = 0;
            for(int row = j; row <= j +2 ; row++){
                for(int cell = k; cell <= k+2; cell++){
                    boxes[count] = &sub(row,cell);
                    count++;
                }
            }
            Cluster* clust = new Cluster(box, boxes, N);
            clusters.push_back(clust);
            for(int n = 0; n < N; n++) {
                boxes[n]->addCluster(clust);
                clust->shoop(boxes[n]->getValue());
            }
        }
    }
}

//----------------------------------------------------------------
SixyBoard::SixyBoard(int n, ifstream &strm) : Board(n, strm, 29) {
    HSixyBoard();
    VSixyBoard();
}

//----------------------------------------------------------------
void SixyBoard::VSixyBoard() {
    short j, k;
    for (j = 1; j <= N; j += 2) {
        for (k = 1; k <= N; k += 3) {
            Square* boxes[N];
            int count = 0;
            for (int row = j; row <= j + 1; row++) {
                for (int cell = k; cell <= k + 2; cell++) {
                    boxes[count] = &sub(row, cell);
                    count++;
                }
            }
            Cluster *clust = new Cluster(vBox, boxes, N);
            clusters.push_back(clust);
            for (int n = 0; n < N; n++) {
                boxes[n]->addCluster(clust);
                clust->shoop(boxes[n]->getValue());
            }
        }
    }
}
//----------------------------------------------------------------
void SixyBoard::HSixyBoard() {
    short j, k;
    for (j = 1; j <= N; j += 3) {
        for (k = 1; k <= N; k += 2) {
            Square* boxes[N];
            int count = 0;
            for (int row = j; row <= j + 3 ; row++) {
                for (int cell = k; cell <= k + 1; cell++) {
                    boxes[count] = &sub(row, cell);
                    count++;
                }
            }
            Cluster *clust = new Cluster(hBox, boxes, N);
            clusters.push_back(clust);
            for (int n = 0; n < N; n++) {
                boxes[n]->addCluster(clust);
                clust->shoop(boxes[n]->getValue());
            }
        }
    }
}

//----------------------------------------------------------------
TradBoard::TradBoard(int n, ifstream &strm, int nType) : Board(n, strm, 29) {
    short j,k;
    for(j = 1; j <= N; j+=3){
        for(k = 1; k <= N; k+=3){
            Square* boxes[N];
            int count = 0;
            for(int row = j; row <= j +2 ; row++){
                for(int cell = k; cell <= k+2; cell++){
                    boxes[count] = &sub(row,cell);
                    count++;
                }
            }
            Cluster* clust = new Cluster(box, boxes, N);
            clusters.push_back(clust);
            for(int n = 0; n < N; n++) {
                boxes[n]->addCluster(clust);
                clust->shoop(boxes[n]->getValue());
            }
        }
    }
}



