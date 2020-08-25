#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<stdint.h>
#include<cmath>
using namespace std;

int main(void)
{
    long long int x;
    long long int t=0;

    cin>>x;

    while(1)
    {
        if(x==1)
            break;
        if(x%2==0)
            x/=2;
        else
            x=(3*x+1);
        t++;
    }

    cout<<"Iteration needed: ";
    cout<<t<<endl;
}
