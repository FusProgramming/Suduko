// Robert Fus
// CSCI 6626 - Object-Orientated Principles & Practices
// Program 3: Game
// File: Square.cpp
// 9/12/2019
#ifndef P1_STATE_STATE_HPP
#define P1_STATE_STATE_HPP



#include "tools.hpp"

class Cluster;

class State {
    public:
        State() = default;
        ~State() = default;
        State(char c);
        void mark(char ch);
        ostream& print(ostream& out);
    protected:
        bool fixed;
        short possList;
        char value;
};

class Square : public State {
    public:
        Square() = default;
        Square(char, short int, short int);
        ~Square();
        void mark(char ch);
        ostream& print(ostream&);
        void addCluster(Cluster * pCl);
        void turnOff(int n);
        char getValue(){ return value; }
        short getPossList() { return possList; }
    private:
        short int col, row;
        vector<Cluster*> clues;
};

inline ostream& operator<< (ostream& out, State st) {
    return st.print(out);
}
inline ostream& operator<< (ostream& out, Square sq) {
    return sq.print(out);
}

#endif //P1_STATE_STATE_HPP