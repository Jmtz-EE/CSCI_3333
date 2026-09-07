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

void Trendtracker:: top_three_trends(vector<string> &T)
{
    //goal find the top three trends
    if (E.empty()) //i infered this from the previous case 
        T = {"", "", ""};

    else //check for 3 largest pops
    {
        int first_pop = 0;
        int second_pop  = 0;
        int third_pop = 0;

        for (int i =0; i < E.size(); i++)
        {

            if (E[first_pop].pop < E[i].pop)
            {
                first_pop = i;
            }             
            else if (E[second_pop].pop < E[i].pop && )
            {
                second_pop = i;
            }
            else if(E[third_pop].pop < E[i].pop)
            {
                third_pop = i; 
            }
        }

        T = {E[first_pop].hashtag, E[second_pop].hashtag, E[third_pop].hashtag}; 
    }


}

void Trendtracker:: remove(string ht) 
{
    for (int i = 0; i < E.size(); i++)
    {
        // I can soot it over 
        if( E[i].hashtag == ht)
        {   
            


        }


    }
}

void Trendtracker:: top_k_trends(vector<string> &T, int k)
{
    int one_index = 0; 
    int one_pop = E[0].pop;
    int new_idx = 0;
   //int two_index = 0;
    int two_pop = E[0].pop;
    for (int i = 0; i < k; i ++)
    {
        two_pop = E[0].pop;
        for (int j = 0; j < E.size(); j++)
        {
            if ( T.empty() &&  E[j].pop > one_pop)
              {  
                one_index = j; 
                one_pop = E[j].pop;
              }
            else 
            {
                if (E[j].pop > two_pop  &&  E[j].pop < one_pop)
                    {
                        new_idx = j;
                        two_pop = E[j].pop;
                    }

                //two_pop = E[j].pop; //update to keep it checking against i-1 or the previous entry 
                //was logical error was comparing agains prev not largest prev
            }
        }
        one_index = new_idx; 
        one_pop = two_pop;
        T.push_back(E[one_index].hashtag); // so this should be ordered by largest to smallest
    }

}