#include<iostream>
#include<cmath>
#include<cstdio>
#include<cstdlib>
using namespace std;

int main(void)
{
    int n,i;
    double s_x=0;                   ///to store the sum of all x
    double s_y=0;                   ///to store the sum of all y
    double s_x2=0;                  ///to store the sum of all x square
    double s_xy=0;                  ///to store the sum of all x*y
    double a0,a1;                   ///for calculation purpose
    double a,b;                     ///to store the outputs
    double x_check,y_check;

    printf("Enter the number of inputs: ");
    cin>>n;
    double x[n];                    ///to store the value of x
    double y[n];                    ///to store the value of y
    double Y[n];

    printf("Enter the values:\n  x  |  y\n");
    for(i=0;i<n;i++)
        cin>>x[i]>>y[i];

    for(i=0;i<n;i++)
        Y[i]=log(y[i]);
    for(i=0;i<n;i++)
    {
        s_x=s_x+x[i];
        s_y=s_y+Y[i];
        s_x2=s_x2+(x[i]*x[i]);
        s_xy=s_xy+(x[i]*Y[i]);
    }
    a0=((s_x2*s_y)-(s_x*s_xy))/((n*s_x2)-(s_x*s_x));
    b=((n*s_xy)-(s_x*s_y))/((n*s_x2)-(s_x*s_x));
    a=exp(a0);

    cout<<"a= "<<a<<endl;
    cout<<"b= "<<b<<endl;

    printf("Enter a value of x from the table to check: ");
    cin>>x_check;
    y_check=a*exp(b*x_check);
    printf("y= ");
    cout<<y_check<<endl;
    for(i=0;i<n;i++)
    {
        if(x_check==x[i])
        {
            printf("Absolute error: ");
            cout<<abs(y_check-y[i]);
        }
    }
}
