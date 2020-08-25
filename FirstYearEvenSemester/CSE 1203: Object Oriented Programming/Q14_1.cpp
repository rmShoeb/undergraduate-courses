#include<iostream>
using namespace std;

class Point
{
public:
    Point(int x, int y)
    {
        ax=x;
        ay=y;
    }
    void print(void)
    {
        cout<<ax<<" "<<ay<<endl;
    }
private:
    int ax;
    int ay;
};
void main(void)             ///1 error in this line
{
    Point a=Point(10,20);
    Point b;                ///another error in this line
}
