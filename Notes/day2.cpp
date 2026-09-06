#include <vector>
using namespace std;
//worst case is the middle never hits our value until all are eliminated 
//O(n) if array is passed by value 
int bs(vector<double> &V , int start, int end, double key)
{
    int s = start;
    int e = end;
    while(s <= e)
    {
        int m = (s+2)/2;
        
        if(key < V[m])
            e = m -1;
        if(key > V[m])
            s = m +1; 
        else 
            return m; 

    }   
    return -1;

}

//sort V from position start to end 
void quickSort(vector <double> &V, int start, int end)
{
    if(start >= end) // base case: 1 or 0 items 
    {
        return;
    }
    else //recursive case: more than 1 item 
    {
        //step 1: partition around a pivot 
        int p = partition(V, start, end);
        
        //step 2:
        quickSort(V, start, p-1);

        //step 3: 
        quickSort(V, p+1, end);
    }




}

int partition(vector<double> &V, int start, int end)
{
    //step Left side 

    //right side 

    

}
void merge(vector<double> &V, int start, int m, int end)
{
    
}

void mergeSort(vector<double> &V, int start, int end)
{
    if (start >= end) //base case : 1 or 0 items 
    {
        return;
    }
    else
    {
        int m = (start + end) / 2;
        mergeSort(V, start, m);//sort left
        mergeSort(V,m+1,end); //sort right 
        merge(V,start,m,end);
    }


}