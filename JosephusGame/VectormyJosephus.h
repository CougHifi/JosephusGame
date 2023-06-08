#pragma once
#include <vector>
#include "destination.h"
class VectormyJosephus
{
    public:
    //VectormyJosephus();
    explicit VectormyJosephus(int n=5, int m=2);//int n=5, int m=2
    ~VectormyJosephus();
   
    void extractingcsv(int n);
    destination ElmininateDestVec();//eliminate vector
    void clear();//clearing the vector
    int currentsize();//finding the current size of the vector
    bool isEmpty();//check if vector is empty.
    void printAllDestinations();
    std::vector<destination> destvec;
    
    void TestVectormyJosephus(int start);
    std::vector<destination>::iterator it;
    destination eliminateDestination(std::vector<destination>::iterator it);
    
    private:
    
    std::string pdata;

    int m{0}; //interval of elimination.
    int n{0};//the number of destination cities.

    
};