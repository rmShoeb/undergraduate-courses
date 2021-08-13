#include<iostream>
#include<cstdlib>
using namespace std;

///nested class
class A
{
public:
    class B
    {
    public:
        int x=0;
    };
    int z=0;
private:
    class C
    {
    public:
        int y=0;
    };
};

///enum
class FontSize
{
public:
    enum{TINY, SMALL, NORMAL, LARGE};
};

///display pointer without any type
void display(void *p)
{
    cout<<*p<<endl;
}


///main function
int main(void)
{
    //cout<<FontSize::LARGE<<endl;
    int *a=new int(2);
    float *b=new float(3.1416);
    display(*a);
    display(*b);
}
