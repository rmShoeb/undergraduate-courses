#include "Point.h"
#include<cmath>
Point::Point()
{
    m_x=0;
    m_y=0;
}
Point::Point(int x,int y)
{
    m_x=x;
    m_y=y;
}
void Point::print()
{
    cout<<"("<<m_x<<","<<m_y<<")"<<endl;
}
int Point::r(void)
{
    return (double)sqrt((m_x*m_x)+(m_y*m_y));
}
