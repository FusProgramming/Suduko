// Robert Fus
// CSCI 6626 - Object-Orientated Principles & Practices
// Program 3: Board
// File: Board.cpp
// 9/21/2019

#include "Board.hpp"

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

    //Breaks here for puzs.txt
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
    return possListStr;
}

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
    Square *rows[N];
    for(short p = j; p<= j ; p++) {
        for(short q = 1; q<= N; q++) {
            rows[q-1] = &sub(p,q);
        }
        clusters.push_back(new Cluster(row, rows));

    }
}

//----------------------------------------------------------------
void Board::createColumn(short k) {
    Square *cols[N];
    for(short q = k; q <= k; q++) {
        for(short p =1; p <= N; p++) {
            cols[p-1] = &sub(p,q);
        }
    clusters.push_back(new Cluster(col, cols));
    }
}
//----------------------------------------------------------------
void Board::createBox(short j, short k) {
    Square* boxes[N];
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
void Board::mark() {
    short row, col;
    char ch;
    cout << "What is the row you want to mark?" << endl;
    cin >> row;
    cout << "What is the column you want to mark?" << endl;
    cin >> col;
    cout << sub(row,col);
    cout << "What number do you want to input?" << endl;
    cin >> ch;
    sub(row,col).mark(ch);
    sub(row,col).getValue();
}

//----------------------------------------------------------------
void Board::restoreState(Frame *frame) {
    State* states = frame->getState();
    for(int n = 0; n < N*N; n++ ) {
        (State&) brd[n] = states[n];
    }
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

//----------------------------------------------------------------
SixyBoard::SixyBoard(int n, ifstream &strm) : Board(n, strm, 29) {
    short j,k;
    for(j = 1; j <= N; j+=3) {
        for (k = 1; k <= N; k += 3) {
            Square *boxes[N];
            int count = 0;
            for (int row = j; row <= j + 2; row++) {
                for (int cell = k; cell <= k + 2; cell++) {
                    boxes[count] = &sub(row, cell);
                    count++;
                }
            }
            Cluster *clust = new Cluster(box, boxes);
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
    for(j = 1; j <= N; j+=4){
        for(k = 1; k <= N; k+=4){
            Square* boxes[N];
            int count = 0;
            for(int row = j; row <= j ; row++){
                for(int cell = k; cell <= k; cell++){
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
    }
}



