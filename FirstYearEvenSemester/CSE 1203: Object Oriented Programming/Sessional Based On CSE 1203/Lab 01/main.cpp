#include "Point.cpp"
#include<conio.h>

int main(void)
{
    Point p;
    p.print();
    cout<<p.r();
    cout<<endl;
    Point q(10,15);
    q.print();
    cout<<q.r();
    cout<<endl;
    getch();
}
