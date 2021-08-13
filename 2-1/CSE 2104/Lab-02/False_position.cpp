#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<algorithm>
using namespace std;

double f(double x)
{
    return ((x*x*x) - (2*x) - 5);
}

int main(void)
{
    double a = 2,b = 3;
    double x0;
    double x=0;
    int n=1;

    printf(" n|     a      |     b      |     x      |    f(x)    \n");
    printf("--------------------------------------------------------\n");
    while(1)
    {
        x0=x;
        x=((a*f(b)-b*f(a))/(f(b)-f(a)));
        if(abs(x0-x)>=0.0001)
        {
            if(f(a)*f(x)>0)
            {
                printf("%2d|%3.10f|%3.10f|%3.10f|%3.10f\n",n,a,b,x,f(x));
                a=x;
            }
            else
            {
                printf("%2d|%3.10f|%3.10f|%3.10f|%3.10f\n",n,a,b,x,f(x));
                b=x;
            }
            n++;
            printf("--------------------------------------------------------\n");
        }
        else
            break;
    }
    printf("Answer: ");
    cout<<x<<endl;
}
