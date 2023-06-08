#include "destination.h"
#include <iostream>
#include <fstream>
/*
explicit destination(int passedpos, int passeddest)
{
    int passedpos;
    int passeddest;
    this->pPos =passedpos; //creating the postion from the passedpos
    this->pDest =passeddest; // creating the destination from the passed dest
}*/
destination::destination()//default constructor.
{
    pDestName = "\0";
    pPos=0;
}

destination::~destination()
{

}
/*printing out my destination and position within the */
void destination::printpos()
{
 
 std::cout << this->pPos <<std::endl;
 
}

int destination::getpos()
{
    return this->pPos;
}
//printing the destination names
void destination::printdestname()
{
   std::cout << this->pDestName <<std::endl;
}
//grabing the name of destination.
string destination::getDestinationName()
{
    return this->pDestName;
}

void destination::setpos(int pos)
{
   pPos=pos;
}
void destination::setdest(string dest)
{
    pDestName=dest;
}

