///finding the maximum using function overloading

///preprocessor directives
#include<iostream>
#include<conio.h>
using namespace std;

///function declaration
double Max(double a, double b)
{
    if(a>b)
        return a;
    else
        return b;
}
int Max(int a, int b)
{
    if(a>b)
        return a;
    else
        return b;
}

///main function
int main(void)
{
    cout<<"The largest number is: "<<Max(15,16)<<endl;
    cout<<"The largest number is: "<<Max(15.0587,15.05)<<endl;
    getch();
}
