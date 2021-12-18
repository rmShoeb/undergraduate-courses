#include<iostream>
#include<assert.h>
using namespace std;
class Point
{
public:
    Point();
    ~Point();
    Point(int, int);
    void rmoveto(Point);
    void print(void);
private:
    int m_x;
    int m_y;
};
Point::Point()          ///constructor
{
    m_x=0;
    m_y=0;
}
Point::~Point()        ///destructor
{

}
Point::Point(int x, int y) ///constructor with parameter
{
    m_x=x;
    m_y=y;
}
void Point::rmoveto(Point p)
{
    m_x+=p.m_x;
    m_y+=p.m_y;
}
void Point::print(void)
{
    cout<<"("<<m_x<<","<<m_y<<")"<<endl;
}
int main(void)
{
    Point *p=new Point(4,5);
    assert(p!=0);
    (*p).print();
    p->rmoveto(Point(10,15));
    p->print();
    delete p;
    p->print();
}
