// Robert Fus
// CSCI 6626 - Object-Orientated Principles & Practices
// Program 6: Exceptions
// File: StreamErrors.cpp
// 10/22/2019

#include "StreamErrors.hpp"
//----------------------------------------------------------------
StreamErrors::StreamErrors(ifstream& strm) : fName(strm) {
    cerr << "Stream Errors Indicated" << endl;
}

//----------------------------------------------------------------
void StreamErrors::print() {
    cerr << "Stream Error: Incorrect File Name." << endl;
}

//----------------------------------------------------------------
StreamFiles::StreamFiles(ifstream& strm) : StreamErrors(strm){
    cerr << "Stream Files Error Indicated" << endl;
}

//----------------------------------------------------------------
void StreamFiles::print() {
    cerr << "Stream Error: Incorrect File Type" << endl;
}

//----------------------------------------------------------------
StreamLoad::StreamLoad(ifstream& strm) : StreamErrors(strm){
    cerr << "Stream Files Error Indicated" << endl;
}

//----------------------------------------------------------------
void StreamLoad::print() {
    cerr << "Stream Error: File Wont Load" << endl;
}
