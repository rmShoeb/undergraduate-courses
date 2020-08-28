#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
using namespace std;

int main(void)
{
    int i,n;
    double s_x=0;       ///to store the sum of all x
    double s_y=0;       ///to store the sum of all y
    double s_x2=0;      ///to store the sum of all x square
    double s_xy=0;      ///to store the sum of all x*y
    double a0,a1;       ///to store the output
    double x_check;     ///to store the checking value of x
    double y_check;     ///to store the checking value of x

    printf("Enter the number of inputs: ");
    cin>>n;
    double x[n];        ///to store all the values of x
    double y[n];        ///to store all the values of y

    printf("Enter the values:\n  x  |  y\n");
    for(i=0;i<n;i++)
        cin>>x[i]>>y[i];

    for(i=0;i<n;i++)
    {
        s_x+=x[i];
        s_y+=y[i];
        s_x2+=(x[i]*x[i]);
        s_xy+=(x[i]*y[i]);
    }
    a0=((s_x2*s_y)-(s_x*s_xy))/((n*s_x2)-(s_x*s_x));
    a1=((n*s_xy)-(s_x*s_y))/((n*s_x2)-(s_x*s_x));

    printf("The value of a0= ");
    cout<<a0<<endl;
    printf("The value of a1= ");
    cout<<a1<<endl;

    printf("Enter a value of x from the given table: ");
    cin>>x_check;

    for(i=0;i<n;i++)
    {
        if(x_check==x[i])
        {
            y_check=a0+(a1*x_check);
            printf("Y= ");
            cout<<y_check<<endl;
            printf("Absolute error: ");
            cout<<abs(y_check-y[i]);
            break;
        }
    }
}
