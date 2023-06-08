#pragma once
#include <iostream>
#include <string>
#include <list>
#include <fstream>
#include <time.h>
#include <cstdlib>
#include "destination.h"
using std::list;

/* Explicit specifier may be used with a constant expression.
 The function is explicit if and only if that constant expression evaluates to true*/
class ListmyJosephus
{
    public:
    
   // ListmyJosephus();
    explicit ListmyJosephus(int n=5, int m=2);//int n=5,int m=2
    ~ListmyJosephus();
    
    
    void ListJosephus(list<int> m);//contains the list of the interval m.
    int currentsize();
    bool isEmpty();
    void clear();
    void TestListmyJosephus(int start);//playing the josephus game list
    destination eliminateDestination(std::list<destination>::iterator it);
    void printalldestinations();//prints all of the destination cities left in sequence from dest with the smallest pos.
    list<destination> destlist;
    void extractingcsv(int n);
    private:
    int m {0};//the interval of elimination
    int n {0};//the number of destination cities at the start of the sim.
    std::string pdata;

};