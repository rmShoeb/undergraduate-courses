#include "Point2.h"
Point::Point(int a, int b)
{
    m_x=a;
    m_y=b;
}
void Point::print(void)
{
    cout<<endl;
}
double Point::R(const Point &a)
{
    return sqrt((a.m_x*a.m_x)+(a.m_y*a.m_y));
}
double Point::area(double r)
{
    return 3.1416*r*r;
}
