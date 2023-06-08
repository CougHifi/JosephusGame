#pragma once
#include <iostream>
#include <string>
#include <vector>
using std::string;
using std::vector;
class destination
{
    public:
    //explicit (int i) :
    explicit destination(int passedpos, int passeddest);
    destination();//default constructor
    ~destination();
    int getpos();
    void setpos(int pos);
    void setdest(string dest);
    string getDestinationName();
    void printpos(); //print current position of the destination
    void printdestname(); //print the namme of destination city
    std::string returndest();    
    
    private:
    int pPos; //number for the position.
    string pDestName; //name of the destination city
    string *pline;
    
};