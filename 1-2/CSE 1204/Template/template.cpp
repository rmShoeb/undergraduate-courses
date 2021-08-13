#ifndef TEMPLATE_H
#define TEMPLATE_H
#include<iostream>
#include<conio.h>
using namespace std;
class Max
{
public:
    template<class T>
    T maximum(T a, T b)
    {
        return (a>b)?a:b;
    }
    template<class T>
    void print(T number)
    {
        cout<<"The largest number is: "<<number<<endl;
    }
};
#endif // TEMPLATE_H
