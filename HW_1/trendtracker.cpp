#include "trendtracker.h"
Trendtracker :: Trendtracker()//O(1) constant
{

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
   // E[E.size() + 1] = n; //adding n  //read that this doesnt work have to resize the array
   //cam use //resize or pushback
    E.push_back(n);
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
        int top_pop = 0;  //moved so it doesnt overwrite

        for (int i =0; i < E.size(); i++)
        {
            if (E[top_pop].pop < E[i].pop ) //what do i do in equal condition ? do i update or not to make <=
            {
                top_pop = i;
            }             
        }
        return E[top_pop].hashtag; 
    }

}

void Trendtracker::top_three_trends(vector<string> &T)
{
    T.clear();

    if (E.empty())
        return;

    int first = 0;

    for (int i = 1; i < E.size(); i++)
    {
        if (E[i].pop > E[first].pop)
        {
            first = i;
        }
    }

    T.push_back(E[first].hashtag);

    if (E.size() == 1)
        return;

    int second = -1;

    for (int i = 0; i < E.size(); i++)
    {
        if (i != first)
        {
            if (second == -1 || E[i].pop > E[second].pop)
            {
                second = i;
            }
        }
    }

    T.push_back(E[second].hashtag);

    if (E.size() == 2)
        return;

    int third = -1;

    for (int i = 0; i < E.size(); i++)
    {
        if (i != first && i != second)
        {
            if (third == -1 || E[i].pop > E[third].pop)
            {
                third = i;
            }
        }
    }

    T.push_back(E[third].hashtag);
}

void Trendtracker:: remove(string ht) 
{
    for (int i = 0; i < E.size(); i++)
    {
        if( E[i].hashtag == ht)
        {   
            E.erase(E.begin() +i); 
            return; 
        }
    }
}

void Trendtracker::top_k_trends(vector<string> &T, int k)
{
    T.clear();

    if (E.empty() || k <= 0)
        return;

    if (k > E.size())
        k = E.size();

    int previous_pop = 0;
    int previous_index = -1;

    // Find the first/top trend
    int top_index = 0;

    for (int j = 1; j < E.size(); j++)
    {
        if (E[j].pop > E[top_index].pop)
        {
            top_index = j;
        }
    }

    T.push_back(E[top_index].hashtag);

    previous_pop = E[top_index].pop;
    previous_index = top_index;

    // Find the remaining k - 1 trends
    for (int i = 1; i < k; i++)
    {
        int new_idx = -1;

        for (int j = 0; j < E.size(); j++)
        {
            // Find a lower popularity than the previous trend
            if (E[j].pop < previous_pop)
            {
                if (new_idx == -1 || E[j].pop > E[new_idx].pop)
                {
                    new_idx = j;
                }
            }

            // If popularity is tied, use the next index.
            // This prevents selecting the same entry again.
            else if (E[j].pop == previous_pop && j > previous_index)
            {
                if (new_idx == -1 || E[j].pop > E[new_idx].pop)
                {
                    new_idx = j;
                }
            }
        }

        if (new_idx == -1)
            break;

        T.push_back(E[new_idx].hashtag);

        previous_pop = E[new_idx].pop;
        previous_index = new_idx;
    }
}