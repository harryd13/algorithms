#include<iostream>
#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<string.h>

using namespace std;

void TowersOfHAnoi(int n,char from_peg,char to_peg , char aux_peg)
{
    if(n == 1)//move this to last ie to peg
    {
        cout << "Move 1* disk from " << from_peg << " to " << to_peg <<"\n";
        return;
    }
    //move all but the greatest from from_peg to  to_peg;
    TowersOfHAnoi(n-1,from_peg,aux_peg,to_peg);
    //now we will move the biggest disk from frompeg to topeg
    cout << "Move the" << n <<  " th disk from " << from_peg << " to " << to_peg <<"\n";
    //now somehow move the aux disks into to peg;
    TowersOfHAnoi(n-1,aux_peg,to_peg,from_peg);
}

int main ()
{
    TowersOfHAnoi(5,'F','T','A');
    return 0;
}