#ifndef POINT_H
#define POINT_H
#include<iostream>
#include<cmath>
using namespace std;
class Point
{
public:
    Point(int, int);
    void print(void);
    int x(void){return m_x;}
    int y(void){return m_r;}
    friend double operator+(const Point&, const Point&);
private:
    int m_x;
    int m_y;
};
#endif // POINT_H
