#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<algorithm>
using namespace std;

double x0;
double x=0;

double f(double x)
{
    return ((x*x*x) - (2*x) - 5);
}

double phi(double x)
{
    double sum= sqrt(2+(5/x)) ;
        return sum;
}

int bisection(double a, double b)
{
    int n=0;

    printf(" n|     a      |     b      |     x      |    f(x)    \n");
    printf("--------------------------------------------------------\n");
    while(1)
    {
        x0=x;
        x=(a+b)/2;
        if(abs(x0-x)>=0.0001)
        {
            n++;
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
            printf("--------------------------------------------------------\n");
        }
        else
            break;
    }
    printf("Answer: ");
    cout<<x<<endl;

    return n;
}

int false_position(double a, double b)
{
    int n=0;

    printf(" n|     a      |     b      |     x      |    f(x)    \n");
    printf("--------------------------------------------------------\n");
    while(1)
    {
        x0=x;
        x=((a*f(b)-b*f(a))/(f(b)-f(a)));
        if(abs(x0-x)>=0.0001)
        {
            n++;
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
            printf("--------------------------------------------------------\n");
        }
        else
            break;
    }
    printf("Answer: ");
    cout<<x<<endl;

    return n;
}

int iteration(double a)
{
    int n=0;
    printf(" n|      a     |    f(a)    \n");
    printf("----------------------------\n");
    while(1)
    {
        n++;
        printf("%2d|%3.10f|%3.10f\n",n,a,phi(a));
        if(abs(a-phi(a))<=.00001)
            {
                printf("Answer: ");
                cout<<phi(a)<<endl;
                break;
            }
        else
            a=phi(a);
        printf("----------------------------\n");
    }
    return n;
}
int main(void)
{
    int ck;
    int bi, fp, it;

    while(1)
    {
        cout<<"1. Bisection Method\n2. False Position Method\n3. Iteration Method\n4. Exit\n";
        cout<<"   Enter your choice: ";
        cin>>ck;
        switch(ck)
        {
        case 1:
            bi=bisection(2,3);
            break;

        case 2:
            fp=false_position(2,3);
            break;

        case 3:
            it=iteration(2);
            break;

        case 4:
            goto xx;

        default:
            cout<<"Wrong Choice...";
        }
    }

    xx:
    printf("\nIteration needed for Bisection Method: %d\n",bi);
    printf("Iteration needed for False Position Method: %d\n",fp);
    printf("Iteration needed for Iteration Method: %d\n\n",it);

    if(fp<bi&&fp<it)
        cout<<"False Position is better."<<endl;
    else if(it<bi&&it<fp)
        cout<<"Iteration Method is better."<<endl;
    else
        cout<<"Bisection Method is better."<<endl;
}
