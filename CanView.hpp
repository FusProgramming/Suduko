/*
 * CanView.hpp
 *
 *  Created on: May 15, 2014, Updated October, 2019
 *      Author: mike and alice
 */

// Interface class for a viewable Sudoku model

#ifndef CANVIEW_HPP_
#define CANVIEW_HPP_

#include <string>
using namespace std;

class CanView {
public:
    virtual ~CanView() =default;
    virtual char getMarkChar(int row, int col) const =0;
    virtual string getPossibilityString(int row, int col) const =0;

};

#endif /* CANVIEW_HPP_ */
