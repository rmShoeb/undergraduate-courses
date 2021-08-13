///using Archimedes Formula
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
using namespace std;

int main(void)
{
    double s0=1;
    long int n=6;
    int i;
    double a,b;
    double pi;

    cout<<"Enter the number of iterations: ";
    cin>>i;

    do
    {
        a=sqrt(1-((s0/2)*(s0/2)));
        b=1-a;
        s0=sqrt((b*b)+((s0/2)*(s0/2)));
        n*=2;
    }
    while(--i);

    pi=(n*s0)/2;
    cout<<"The value of Pi="<<pi<<endl;
}
