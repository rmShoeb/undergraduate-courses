#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;

double f(double x)
{
    return ((x*x*x)-(2*x)-5);
}

double phi(double x)
{
    return (1/sqrt(x+1));
}

int main(void)
{
    double a;
    int n=0;

    cout<<"Enter value of a: ";
    cin>>a;
    while(1)
    {
        n++;
        printf("%d | %f | %f\n",n,a,phi(a));
        if(abs(a-phi(a))<=0.00001)
            break;
        else
            a=phi(a);
    }
}
