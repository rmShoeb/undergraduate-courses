#include<iostream>
#include<conio.h>
using namespace std;
int main(void)
{
    const int x(17);
    int y(42);
    int *p1;
    const int *p2;
    const int *const p3(&x);
    int *const p4(&y);
    p1=&y;
    *p1*=2;
    p2=&x;
    (*p4)++;
    cout<<"p1= "<<hex<<(int)p1<<", *p1= "<<dec<<*p1<<endl
        <<"p2= "<<hex<<(int)p2<<", *p2= "<<dec<<*p2<<endl
        <<"p3= "<<hex<<(int)p3<<", *p3= "<<dec<<*p3<<endl
        <<"p4= "<<hex<<(int)p4<<", *p4= "<<dec<<*p4<<endl;
    getch();
}
