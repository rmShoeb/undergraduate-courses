#include<iostream>
#include<iomanip>
#include<conio.h>
using namespace std;
int main(void)
{
    const int i=14;
    const double c=2.99792458e8;
    cout<<c<<" "<<i<<endl;
    cout<<setiosflags(ios::uppercase)<<"foo "
        <<hex<<c<<" "<<i<<endl;
    cout<<setiosflags(ios::fixed)<<resetiosflags(ios::uppercase)<<c<<" "<<i<<endl;
    cout<<setiosflags(ios::scientific|ios::showpos)<<oct<<c<<" "<<i<<endl;
    getch();
}
