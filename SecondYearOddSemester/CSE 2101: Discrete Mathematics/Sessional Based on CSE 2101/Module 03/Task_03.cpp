#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<vector>
#include<ctime>
#include<algorithm>
using namespace std;

int main(void)
{
    int n;
    vector<int>input;
    int i,temp,check;

    printf("Enter the size of your input: ");
    cin>>n;
    srand(time(0));
    for(i=0;i<n;i++)
    {
        temp=rand()%101;
        input.push_back(temp);
    }
    printf("Enter the value you want to find: ");
    cin>>check;

    for(i=0;i<n;i++)
    {
        if(input[i]==check)
            printf("The value is found at position %d\n",i+1);
    }
}
