#include<iostream>
#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<string.h>

using namespace std;

class sort 
{
    private:
    int input[10];

    public:
    void writeArray();
    void printArray();
    void insSort();

};

void sort::writeArray()
{
    int i;
    srand(time(NULL));
    for(i = 0;i<10;i++)
    {
        input[i] = rand()%100 ; 
    }
}
void sort::printArray()
{
     int i;
    for(i = 0;i<10;i++)
    {
        cout << input[i] <<"\n"; 
    }
}
void sort::insSort()
{
     int i,j;
     int key;
     for (i = 1;i<10;i++)
     {
         key = input[i];
         j = i-1;
         while(j>=0 && key < input[j])
         {
             input[j+1] = input[j];
             j--;
         }
         input[j+1] = key;
     }
}

int main()
{
    sort s;
    s.writeArray();
    cout << "Sorting an array of 10 integers via insertion.\n";
    cout << "UNSORTED array is ______________________________:\n";
    s.printArray();
    cout << "SORTED array is ________________________________:\n";
    s.insSort();
    s.printArray();
    cout << "_____________________________________________end_\n";
    return 0;
}