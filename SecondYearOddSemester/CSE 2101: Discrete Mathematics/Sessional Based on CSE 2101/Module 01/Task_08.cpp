#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
using namespace std;

int main(void)
{
    int x,y,z;

    cin>>z;

    for(x=0;x<=z;x++)
    {
        y=(int)sqrt((z*z)-(x*x));
        if((x*x)+(y*y)==(z*z))
            printf("Possible for (%d,%d)\n",x,y);
    }
}
