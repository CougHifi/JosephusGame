#include <fstream>
#include <iostream>
#include <time.h>
#include <cstdlib>
#include "VectormyJosephus.h"
/*My code is similar to Vonderborsh since I used his code as a reference.
https://github.com/vonderborch/CS223/blob/master/PP1/ProgrammingProject1/ProgrammingProject1/VectorMyJosephus.cpp
*/



//explicit constructor.
VectormyJosephus::VectormyJosephus(int n, int m)
{
  
}


VectormyJosephus::~VectormyJosephus()
{

}
//helpped alot by Ryan tutor on this one.
void VectormyJosephus::extractingcsv(int n)
{
    char delim =',';
    destination destcsv;
    int position=1;
    int line; 
    int currentline;
    srand(time(NULL));
    line = rand() % 24 + 1;
    std::fstream destfile;
    destfile.open("destinations.csv");
    if(destfile.is_open())
    {
        getline(destfile,pdata);
    }
    
    while(getline(destfile,pdata,delim))
    {

       
        /*You are comparing the currentline with the randomized line
        and then you are to set the position and destination and then push back on the vector.*/
        if(currentline == line)
        {
           for(;position<n; position++)//incrementing the position if the position is < n
           {
               getline(destfile,pdata, delim);
               destcsv.setdest(pdata);
               destcsv.setpos(position);
               destvec.push_back(destcsv);    
           }
        }
       currentline ++;
       
        
        
    }
    if(destfile.bad())//quick check to see if the file is bad.
    {
        std::cout<<"Destination File is not loading"<<std::endl;
    }
/**/
}


void VectormyJosephus::clear()
{
    this->destvec.clear(); //clears my stl vector called destvec
}

int VectormyJosephus::currentsize()
{
    return destvec.size(); //This checks the size of the stl vector.
}

bool VectormyJosephus::isEmpty()
{
   return this->destvec.empty(); //This checks to see if the stl vector function is empty or not.
}
//using documentation 
//https://docs.microsoft.com/en-us/cpp/standard-library/vector-class?view=vs-2019
void VectormyJosephus::printAllDestinations()
{
    
    std::vector<destination>::iterator it = destvec.begin();
    for(vector<destination>::size_type i =0; i<=destvec.size();i++)
    {
        (*it).printdestname();
        std::cout<<"Destination Left:"<<std::endl;
        std::advance(it,1);
    }
    std::cout<<"\nJobDone\n";//Job is indeed done
}
//Eliminating destinations.
//Noah Howell has helped me with this function in the loop.
destination VectormyJosephus::ElmininateDestVec()
{
    vector<destination>::size_type count=0;
    
    destination d;
    
    for(;count <=(vector<destination>::size_type)m;count++)
    {
        if(count==destvec.size())
        {
            it=destvec.begin();//setting iterator at the beginning.
        }
        else
        {
            std::advance(it,1);//Advancing the iterator by 1
        }
        
    }
    d=eliminateDestination(it);
    return d;      
}

destination VectormyJosephus::eliminateDestination(std::vector<destination>::iterator it)
{
    destination d =(*it);
    destvec.erase(it);
    return d;
}

void VectormyJosephus::TestVectormyJosephus(int start)
{
    
    std::vector<destination>::iterator it = destvec.begin();
        std::advance(it,start);
        for (int i =1; i<=m;i++)
        {
            if(start+i==n)
            {
                it=destvec.begin();
            }
            else
            {
                std::advance(it,1);
            }
            n--;
            //complains about unused variable here.
             //to find where it would start on the next cycle.
            eliminateDestination(it);
            if(n>1)
            {
                int newbeginning;
                newbeginning=(std::distance(destvec.begin(),it)) %n;
                VectormyJosephus(newbeginning,5);
            }
            else if(n==1)
            {
                printAllDestinations();
            }
            
        }
}
