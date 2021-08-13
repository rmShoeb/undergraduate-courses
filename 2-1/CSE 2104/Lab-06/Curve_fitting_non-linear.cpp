#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
using namespace std;

int main(void)
{
    int i,n;
    double s_x=0;
    double s_y=0;
    double s_x2=0;
    double s_x3=0;
    double s_x4=0;
    double s_x2y=0;
    double s_xy=0;
    double d,dC,dA,dB,a,b,c;
    double x_check,y_check;

    printf("Enter the number of inputs: ");
    cin>>n;
    double x[n];
    double y[n];

    printf("Enter the values:\n  x  |  y\n");
    for(i=0;i<n;i++)
        cin>>x[i]>>y[i];

    for(i=0;i<n;i++)
    {
        s_x=s_x+x[i];
        s_y=s_y+y[i];
        s_x2=s_x2+(x[i]*x[i]);
        s_xy=s_xy+(x[i]*y[i]);
        s_x3=s_x3+(x[i]*x[i]*x[i]);
        s_x4=s_x4+(x[i]*x[i]*x[i]*x[i]);
        s_x2y=s_x2y+(x[i]*x[i]*y[i]);
    }
    d=n*(s_x2*s_x4-s_x3*s_x3)-s_x*(s_x*s_x4-s_x2*s_x3)+s_x2*(s_x*s_x3-s_x2*s_x2);
    dA=s_y*(s_x2*s_x4-s_x3*s_x3)-s_x*(s_xy*s_x4-s_x2y*s_x3)+s_x2*(s_xy*s_x3-s_x2*s_x2y);
    dB=n*(s_xy*s_x4-s_x2y*s_x3)-s_y*(s_x*s_x4-s_x2*s_x3)+s_x2*(s_x*s_x2y-s_x2*s_xy);
    dC=n*(s_x2*s_x2y-s_x3*s_xy)-s_x*(s_x*s_x2y-s_x2*s_xy)+s_y*(s_x*s_x3-s_x2*s_x2);
    a=dA/d;
    b=dB/d;
    c=dC/d;

    cout<<"a0="<<a<<"\na1="<<b<<"\na2="<<c<<endl;

    printf("Enter a value of x from the table to check: ");
    cin>>x_check;
    printf("Value of y: ");
    y_check=a+(b*x_check)+(c*x_check*x_check);
    printf("Y= ");
    cout<<y_check<<endl;
    for(i=0;i<n;i++)
    {
        if(x_check==x[i])
        {
            printf("Absolute error: ");
            cout<<abs(y[i]-y_check);
        }
    }
}
