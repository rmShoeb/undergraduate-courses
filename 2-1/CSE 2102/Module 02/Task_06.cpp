#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<cmath>
#include<cstring>
#include<ctype.h>
#include<algorithm>
using namespace std;

int main(void)
{
    int i=(-100);
    int temp_right;
    int temp_left;

    do
    {
        temp_left=floor(2*i);
        temp_right=floor(i)+floor(i+1/2.0);
        if(temp_left==temp_right)
            cout<<true;
        else
            cout<<false;
        printf(" for value ");
        cout<<i<<endl;
        i++;
    }
    while(i<=100);
}
