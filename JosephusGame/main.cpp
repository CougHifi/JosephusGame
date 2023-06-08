/*
Name: Cougar Fischer
Assignment: PA2
Date: 9/16/2020
Other Requirements:
Does the processor of the machine that is running the algorithms matter? Will you receive the same timing statistics on every machine?
answer: Algorithms does matter when it comes to the processor. Since all computers have different processors others will compute slower than others depending on how its made.
So the timing statistics on every machine will differ depending on the processor you have in that specific machine.

Which of the two implementations(list vs.vector) performs best and under what conditions? Does it depend on the input?
answer: When it comes to the deletion between a list and a vector. The list is more efficent than a vector. This is because to insert a element into the list either at the start, end, or middle only has two pointers being swapped.
while for the vector the insertion and deletion at the start or in the middle will have to make all the elements shift by one within that vector.
With this there is a insufficient contiguous memory within the vector at the time of the insertion where a new contiguous memory will be allocated and the elements will be copied in there.

How does the running time dependency on the parameter N compares with the dependency on the parameter M?
answer: 
*/

#include <ctime>
#include <fstream>
#include "VectormyJosephus.h"
#include "ListmyJosephus.h"

int main(void)
{
    VectormyJosephus josevec;
    ListmyJosephus listjose;
    int info;
    //int L1=1;
   // int L2=5;
    int vpass = 1;
    int vexecution = 5;
    int LPass =1;
    int LExecution = 5;

    std::ofstream logfile ("results.log");
    if(logfile.is_open())
    {
        std::cout<<"success input to screen"<<std::endl;
    
        //I have been helpped by Noah Howell on redoing the main.
        
        listjose.extractingcsv(info);
        clock_t start = clock();
        josevec.TestVectormyJosephus(info);
        josevec.TestVectormyJosephus(vpass);
        josevec.TestVectormyJosephus(vexecution);
        josevec.printAllDestinations();
    
        clock_t end=clock();
        //writing it out to the file.
        logfile<<info;
        logfile<<vpass;
        logfile<<vexecution;
        std::cout << "\n\n---List Josephus Time---\nElapsed time in seconds: " <<(double)(end-start)/CLOCKS_PER_SEC << std::endl;
        logfile << "\n\n---List Josephus Time---\nElapsed time in seconds: " <<(double)(end-start)/CLOCKS_PER_SEC << std::endl;
        logfile.close();
    }
    //file closed.

    logfile.open("results.log");
    if(logfile.is_open())
    { 
        clock_t start = clock();
        std::cout<<"Succcess input List to screen"<<std::endl;
        listjose.TestListmyJosephus(info);
        listjose.TestListmyJosephus(LPass);
        listjose.TestListmyJosephus(LExecution);
        listjose.printalldestinations();
        
        //end=clock();
        logfile<<info;
        logfile<<vpass;
        logfile<<vexecution;
        clock_t end=clock();
        std::cout << "\n\n---List Josephus Time---\nElapsed time in seconds: " <<(double)(end-start)/CLOCKS_PER_SEC << std::endl;
        logfile << "\n\n---List Josephus Time---\nElapsed time in seconds: " <<(double)(end-start)/CLOCKS_PER_SEC << std::endl;
        logfile.close();

    }
   
    //start=clock();
    
    //listjose.extractingcsv(info);//populated with the information from the csv.
    
    
    
    /*make sure to pass in the n value into the list. it will read till it reaches that val.
    you will need to have a for loop to call the destinations n-1 times.
    make a list and fill it with the destination
    make a list and call the function what ever you want

    you will do the same with the vector. 
    call the clock first in the whole list. once you get to the single dest stop the clock.
    */
   
}