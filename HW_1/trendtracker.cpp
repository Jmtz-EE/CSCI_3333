#include "trendtracker.h"

//what does tracking no hashtags mean? assuming it means empty
Trendtracker :: Trendtracker()//O(1) constant
{
    //assuming i have to initilize E to null or 0 
    //E ; // i am not to familiar with initializing vectors to empty/0/null
    //seems that declaring it creates just an empty vector should be good enough
    //issue i see here is that the E is overwritten everytime we create a class object
    //no thats wrong since each class object will have its own E
}

void Trendtracker :: insert(string ht)
{   //Goal: add new entry if not in E 
    for (int i = 0; i < E.size() ; i++ ) //O()
    {
        if ( E[i].hashtag == ht)
            return; //added to return if the if is triggered    
    }
    Entry n;
    n.hashtag = ht;
    n.pop = 0 ; //tweeted zero times
    E[E.size() + 1] = n; //adding n 
}

int Trendtracker :: size() // O(1) 
{
    //Goal: check the size of the vector
    return E.size(); // .size() is O(1) check as to why that is
}

void Trendtracker:: tweeted(string ht)
{
    //Goal: Add 1 to pop
    //find the hastag 
    for (int i = 0; i < E.size(); i ++ )
    {
        if ( ht == E[i].hashtag) 
            E[i].pop ++; 
            //i recall in CSI we spoke of ++x or x++
    }
    return ; //if hashtag does not exist
}

int Trendtracker:: popularity(string name)
{
    //Goal: return E.pop
    for (int i = 0; i < E.size(); i++)
    {
        if (E[i].hashtag == name)
        {
            return E[i].pop;
        }
    }
    return -1; //if for loop runs and no match is found 
}

string Trendtracker:: top_trend()
{
    //check if trendtracker is empty
    if (E.empty())
        return "";
    else //check for largest pop
    {
        for (int i =0; i < E.size(); i++)
        {
            int top_pop = 0;  

            if (E[top_pop].pop < E[i].pop ) //what do i do in equal condition ? do i update or not to make <=
            {
                top_pop = i;
            }             
            return E[top_pop].hashtag; 

        }
    }

}

void Trendtracker:: top_three_trends(vector<string> &T)
{
    //goal find the top three trends
    if (E.empty()) //i infered this from the previous case 
        T = {"", "", ""};

    else //check for 3 largest pops
    {
        for (int i =0; i < E.size(); i++)
        {
            int first_pop = 0; 
            int second_pop  = 0; 
            int third_pop = 0;

            if (E[first_pop].pop < E[i].pop)
            {
                first_pop = i;
            }             
            else if (E[second_pop].pop < E[i].pop)
            {
                second_pop = i;
            }
            else if(E[third_pop].pop < E[i].pop)
            {
                third_pop = i; 
            }
            
            T = {E[first_pop].hashtag, E[second_pop].hashtag, E[third_pop].hashtag}; 

        }
    }


}

void Trendtracker:: remove(string ht)
{

}

void Trendtracker:: top_k_trends(vector<string> &T, int k)
{

}