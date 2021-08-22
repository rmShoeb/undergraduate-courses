#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<stdint.h>
using namespace std;

int main(void)
{
    long long int x;
    long long int T;

    cout<<"Enter your value: ";
    cin>>x;

    T=0;
    while(x!=1)
    {
        if(x%2==0)
        {
            x/=2;
            T++;
        }
        else
        {
            x=3*x+1;
            T++;
        }
    }
    cout<<"Total number of iterations: ";
    cout<<T<<endl;
}
