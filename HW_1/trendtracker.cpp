#include "trendtracker.h"

//what does tracking no hashtags mean? assuming it means empty
Trendtracker :: Trendtracker()//O(1) constant
{
    //assuming i have to initilize E to null or 0 
    E ; // i am not to familiar with initializing vectors to empty/0/null
    //seems that declaring it creates just an empty vector should be good enough
    //issue i see here is that the E is overwritten everytime we create a class object
    //no thats wrong since each class object will have its own E
}

void Trendtracker :: insert(string ht)
{
    //maybe ill make it a smart insert nvm doesnt make sense as the popularity changes the list cant be ordered until i have all entries 
    //add a check to see if it already is in trendtracker
    //can do a for loop which is O(n) maybe 
        //in the loop have a add if it wasnt found O(1)
    for (int i = 0; i < E.size() ; i++ )
    {
  

    }
}

int Trendtracker :: size()
{
    //check the size of the vector
    return E.size(); // .size() is O(1) check as to why that is
}

void Trendtracker:: tweeted(string ht)
{
    //where am i storing the number of times it is tweeted i alreay have t
    //nvm its entry to pass the entry.hashtag as the name 
    //then the entry.pop as times it was tweeted and 
    //the 
}

int Trendtracker:: popularity(string name)
{
    //this is E.pop check 
    //loop through vector check the name == E[i].hashtag if yes then check the
    //E.[i].pop
}

string Trendtracker:: top_trend()
{

}

void Trendtracker:: top_three_trends(vector<string> &T)
{

}

void Trendtracker:: remove(string ht)
{

}

void Trendtracker:: top_k_trends(vector<string> &T, int k)
{

}