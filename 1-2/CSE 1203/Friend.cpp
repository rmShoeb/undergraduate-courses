#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<conio.h>
using namespace std;


class Hudai
{
public:
    void set_value(int);
    int get_value(void);
    friend void print(void);

protected:
    int pro;

private:
    int pri;
};

void Hudai::set_value(int x=0)
{
    pri=pro=x;
}

int Hudai::get_value()
{
    return pri;
}

void print(Hudai x)
{
    cout<<x.pri<<end;     ///friend_functions_cannot_access_private_members
    cout<<x.pro<<endl;    ///friend_function_cannot_access_protected_members
}


int main(void)
{
    Hudai baal;

    baal.set_value(10);
    print(baal);

    getch();
    return 0;
}
