#include "trendtracker.h"

Trendtracker :: Trendtracker(string filename)
{
/* Read wrong we need O(n) so simple loop should work 
*/
string s; 
//read from the file
ifstream fin(filename); //ios::in ios::out 
// fstream, ifstream , ofstream
while(!fin.eof()) //O(n )
{
    file >> s; //O(1)
    E.push_back(s); //O(1)
}

}

int Trendtracker :: size() 
{
    E.size(); //O(1)

}

void Trendtracker :: tweeted(string ht)
{
    //must run in O(log(n)) so it must be able to 
    //split the input n to n/2 ..... 1 as needed
    //since its not O(n) i cant look at every entry 
    //then add 1
    //if in alphabetical order i can look at the ASCII and compare that way
     

}

int Trendtracker :: popularity(string name) 
{
    //must run in O(log(n)) need to do some split on the list
    //like a binary search and return E.
}

string Trendtracker :: top_trend()
{
    //run in O(1) so no comparing is allowed ? 
    //maybe keep track of which it is like how size does 
        //yes exactly that since we have top three just pass by ref vector[0]

}

void Trendtracker :: top_three_trends(vector<string> &T) 
{
    //pass by ref S;  O(1)
    //when is S populated 
    //have to find the top three at some point 

}

int Trendtracker :: search(string ht)
{

}
