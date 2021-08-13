#ifndef POINT_H
#define POINT_H
#include<iostream>
using namespace std;
class Point
{
public:
    Point(int, int);
    void print(void);
    int x(void){return m_x;}
    int y(void){return m_y;}
    //friend Point operator++(const Point&, int);
    Point operator++(int);
    //friend Point operator-(const Point&);
    //Point operator-();

private:
    int m_x;
    int m_y;
};
#endif // POINT_H
