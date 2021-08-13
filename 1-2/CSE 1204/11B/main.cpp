#include "Point.cpp"
/*Point operator-(const Point &a)
{
    Point c;
    c.m_x=-a.m_x;
    c.m_y=-a.m_y;
    return c;
}*/
/*void operator++(const Point& a)
{
    //Point c;
    //c.m_x=++a.m_x;
    //c.m_y=++a.m_y;
    a.m_x=a.m_x+1;
    a.m_y=a.m_y+1;
    //return c;
}*/
/*Point operator++(const Point& a, int x)
{
    Point c;
    c.m_x=a.m_x+1;
    c.m_y=a.m_y+1;
    //a.m_x=a.m_x+1;
    //a.m_y=a.m_y+1;
    return c;
}*/
int main(void)
{
    Point x(1,2);
    Point y;
    //++x;
//    x++;
    //x.print();
    //y=++x;
    //++y;
    //y.print();
    y=x++;
    y.print();
}
