#include "Point.h"
Point::Point(int x=0, int y=0)
{
    m_x=x;
    m_y=y;
}
void Point::print(void)
{
    cout<<"("<<m_x<<","<<m_y<<")"<<endl;
}
/*Point Point::operator-()
{
    Point c;
    c.m_x=-this->m_x;
    c.m_y=-this->m_y;
    return c;
}*/
Point Point::operator++(int)
{
    Point c;
    c.m_x=this->m_x+1;
    c.m_y=this->m_y+1;
    return c;
}
