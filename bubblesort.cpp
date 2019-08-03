#include<iostream>
#include<cstdio>

using namespace std;

void sort_bubble( int arr[],int size)
{
    int z; //for swapping
    int swap_count = 0;
    for(int i = 0;i < size;i++) // since in each pass the heaviest int will sink to bottom
    {
        for(int j = 1; j< size ;j++)//bubbling for loop
        {
            if(arr[j] < arr[j-1] )
            {
                z = arr[j];
                arr[j] = arr[j-1];
                arr[j-1] = z;
                swap_count += 1;

            }
            

        }
        if (swap_count == 0)
            break;
        
    }

}
int main(){
    //test
    int myArray[] = {2,4,0,0,-1};
    sort_bubble(myArray,5);
    for(int i = 0;i< 5;i++){
        printf("..%d\n",myArray[i]);
    }
    return 0;
}