///using Machin's formula
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<algorithm>
using namespace std;

int main(void)
{
    int i,n;
    double pi=0;
    double temp;
    double a,b;

    printf("pi=16tan-1(1/a)-4tan-1(b)\n");
    printf("Enter a: ");
    cin>>a;
    printf("Enter the number of iteration: ");
    cin>>n;

    a=(1.0/a);
    b=((2*a)/(1-(a*a)));
    b=((2*b)/(1-(b*b)));
    b=((b-1)/(b+1));

    for(i=0;i<n;i++)
    {
        temp=16*((pow(-1,i)*(pow(a,(2*i+1))))/(2*i+1));
        pi+=temp;
        temp=4*((pow(-1,i)*(pow(b,(2*i+1))))/(2*i+1));
        pi-=temp;
    }
    cout<<pi;
}
