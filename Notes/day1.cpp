using namespace std;
#include <iostream>
#include <string>
#include <queue>
#include <chrono>//used to time the code 
//return the index of the smallest value
//big o is not worst,best, or average is is the ceiling or upper bounding 
//that is in the range of start to end inclusive
//let n be the size of search space: n = end-start +1
//Run time: O(1) + O(1) + O(1) + O(n)
int findsmallest(vector<double> &V, int start, int end)
{
    int smallestSeen = start;//O(1)

    //run time: n* O(1) = O(n)
    for(int i = start; i<=end; i++)//#iterations : n 
    {
        if(V[i] < V[smallestSeen])//O(1)
            smallestSeen = i;
    }
    return smallestSeen;//O(1)

}

//let n be the size of the the vector V, n = V.size()
//looking for number or arithemic operations the CPU makes
//Run time: O(1) + O(n) = O(n)
void printList(vector<double> V)
{//how long does it take to read the vector 
    //vector is a class that has an array in it it has a copy contructor it is pass by value not pass by reference 
    //the vector has a copy constructor so i is pass by value and has to make a copy when passing it over so reading the vector is O(n)
    //an array is pass by ref 
    //to lower the runtime change it to pass by reference riskier can make changes to real one but makes it faster now you are passing directly memory location 
    for (int i = 0; i < V.size(); i++)
    {
        cout << V[i] << endl; //0(1) //big O hides constant as long it is a bounded constat it is big O(1)
    }
}

void selectionSort(vector<double> &X) //O(1) passing by ref so constant
{ //n * O(n) = O(n^2)
    for(int i = 0 ; i <= X.size(); i++)//iterations: n
    {   //total of loop body: O(n) + o(1) = O(n)
        int smallest = findsmallest(X, i, X.size() -1); //O(n)

        swap(X[i] , X{smallest});//o(1)

    }

    //stress test with large list 
    int huge = 100; 
    vector <double> L;
    for (int i = 0; i < huge; i++)
    L.push_back(rand());
    selectionSort(L);



//timing code 
//look at system time before after then subtract 

//data structures heap 
    //insert items and any times you insert it will only take O(logn) where n are the items in the heap 
    //remove smallest O(logn)
//for loop number of loops and the cost of the body
void heapSort(vector<double> & X)
{
priority_queue<double> H; //a heap 
step 

//heap returns top and pop heap returns actual biggest 
}
}


