#include<iostream>
#include<cstdlib>
#include<cstdio>
using namespace std;

int main(void)
{
    int x;
    x=1;

    xx:
        cout<<x<<endl;
        x++;
        if(x>10)
            goto yy;
        else
            goto xx;

    cout<<"Just for checking...........failed"<<endl;
    yy:
        cout<<"Success"<<endl;
}
