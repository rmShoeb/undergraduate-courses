#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<algorithm>
using namespace std;

int main(void)
{
    double xt;
    double x;
    double xa,xr,xp;

    xt=sqrt(2);

    cin>>x;

    xa=abs(xt-x);
    xr=xa/xt;
    xp=xr*100;

    cout<<"Xa: "<<xa<<endl;
    cout<<"Xr: "<<xr<<endl;
    cout<<"Xp: "<<xp<<endl;
}
