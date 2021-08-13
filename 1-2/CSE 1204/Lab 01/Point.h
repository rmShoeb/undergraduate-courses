#ifndef __POINT_H
#define __POINT_H
#include<iostream>
using namespace std;

class Point
{
public:
    Point();
    Point(int, int);
    void print();
    int r(void);
private:
    int m_x;
    int m_y;
};
#endif // __POINT_H
