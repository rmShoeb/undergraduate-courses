///pre-processor directives
#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<conio.h>
using namespace std;
#ifndef POINT_H
#define POINT_H

///class declaration
class Point
{
public:
    Point(int, int);
    friend ostream& operator<<(ostream&, const Point&);   ///friend function
    friend istream& operator>>(istream&, Point&);
    //ostream& operator<<(ostream&);        ///member function
private:
    int m_x;
    int m_y;
};
#endif // POINT_H

///constructors
Point::Point(int x=0, int y=0)
{
    m_x=x;
    m_y=y;
}

/*///member function
ostream& Point::operator<<(ostream& out)
{
    out<<this->m_x<<","<<this->m_y;
    return out;
}*/

///friend function
ostream& operator<<(ostream& out, const Point& p)
{
    out<<"("<<p.m_x<<","<<p.m_y<<")";
    return out;
}

istream& operator>>(istream& in, Point& p)
{
    in>>p.m_x>>p.m_y;
    return in;
}
class Point2
{
public:
    Point2(int x=0, int y=0)
    {
        m_x=x;
        m_y=y;
    }
private:
    int m_x;
    int m_y;
};
///main function
int main(void)
{
    Point p,q;
    Point2 x;
    cin>>p;
    cout<<x.m_x;
    q=p;
    cout<<p<<endl;
    cout<<q<<endl;
    //cout<<p<<"\n"<<Point()<<endl;
    getch();
}
