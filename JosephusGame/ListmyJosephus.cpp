#include "ListmyJosephus.h"

ListmyJosephus::ListmyJosephus(int n, int m)//normal constructor
{

}

ListmyJosephus::~ListmyJosephus()//destructor
{

}


//check list size.
int ListmyJosephus::currentsize()
{
    return destlist.size();
}

bool ListmyJosephus::isEmpty()
{
   return this->destlist.empty();
}

void ListmyJosephus::clear()
{
    this->destlist.clear();
}
void ListmyJosephus::extractingcsv(int n)
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
               destlist.push_back(destcsv);    
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


void ListmyJosephus::printalldestinations()
{
    list<destination>::iterator it = destlist.begin();
    for(list<destination>::size_type i =0; i<=destlist.size(); i++)
    {
        (*it).printdestname();
        std::cout<<"Destination in List Left:"<<std::endl;
        std::advance(it,1);
    }
    std::cout<<"\nJoblistdone\n";
}



destination ListmyJosephus::eliminateDestination(std::list<destination>::iterator it) {
        //Must return a copy of the destination erased.
        destination d = (*it);
        destlist.erase(it);
        return d;
    }
    
   //I was helpped by Noah Howell on this function
 void ListmyJosephus::TestListmyJosephus(int start)
 {
    
     std::list<destination>::iterator it = destlist.begin();
        std::advance(it,start);
        for (int i =1; i<=m;i++)
        {
            if(start+i==n)
            {
                it=destlist.begin();
            }
            else
            {
                std::advance(it,1);
            }
            n--;
            
            eliminateDestination(it);
            if(n>1)
            {
                int newstart; //to find where it would start on the next cycle.
            newstart=(std::distance(destlist.begin(),it)) %n;
                ListmyJosephus(newstart,5);
            }
            else if(n==1)
            {
                printalldestinations();
            }
            
        }
 }