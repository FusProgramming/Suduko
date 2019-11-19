// Robert Fus
// CSCI 6626 - Object-Orientated Principles & Practices
// Program 3: Board
// File: Board.hpp
// 9/21/2019

#ifndef P2_SQUARE_BOARD_HPP
#define P2_SQUARE_BOARD_HPP

#include "tools.hpp"
#include "Square.hpp"
#include "StreamErrors.hpp"
#include "GameErrors.hpp"
#include "Cluster.hpp"
#include "CanView.hpp"
#include "Frame.hpp"

class Frame;
class Board : public CanView {
    public:
        Board(int n, ifstream& strm, int nType) throw (StreamErrors, GameErrors);
        ~Board();
        Square& sub(int j, int k);
        ostream& print(ostream& out);
        ostream& printCluster(ostream&);
        void makeClusters();
        State getSquare(int n) const;
        void restoreState(Frame* frame);

    void mark();

private:
        void getPuzzle(int n, ifstream& strm);
        ifstream& data;
        short int left = '-';

    void createRow(short j);
        void createColumn(short k);
        void createBox(short j, short k);
        char getMarkChar(int j, int k) const;
        string getPossibilityString(int j, int k) const;
    protected:
        int N;
        Square* brd;
        vector<Cluster*> clusters;
};
class DiagBoard : public Board {
    public:
        DiagBoard(int n, ifstream& strm);
        ~DiagBoard()= default;
    private:
        void DiagBoardOne();
        void DiagBoardTwo();


};
inline ostream& operator<< (ostream& out, Board& b) {
    return b.print(out);
}

#endif //P2_SQUARE_BOARD_HPP
