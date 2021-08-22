#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
using namespace std;

int main(void)
{
    int x,y,z;
    cin>>z;

    cout<<"Showing possibilities for x2+y2=z2"<<endl;
    for(x=0;x<=z;x++)
    {
        y=(int)sqrt((z*z)-(x*x));
        if((x*x+y*y)==(z*z))
            printf("Possible for (%d,%d)\n",x,y);
    }
    cout<<"\n";

    cout<<"Showing possibilities for x3+y3=z3"<<endl;
    for(x=0;x<=z;x++)
    {
        for(y=0;y<=z;y++)
        {
            if((x*x*x+y*y*y)==z*z*z)
                printf("Possible for (%d,%d)\n",x,y);
        }
    }
}
