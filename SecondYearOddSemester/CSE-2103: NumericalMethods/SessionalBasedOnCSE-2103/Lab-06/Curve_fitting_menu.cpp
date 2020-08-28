#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
using namespace std;

void linear_curve(void)
{
    int i,n;
    double s_x=0;
    double s_y=0;
    double s_x2=0;
    double s_xy=0;
    double a0,a1;
    double x_check;
    double y_check;

    printf("Enter the number of inputs: ");
    cin>>n;
    double x[n];
    double y[n];

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

    printf("a0= ");
    cout<<a0<<endl;
    printf("a1= ");
    cout<<a1<<endl;

    printf("Enter a value of x: ");
    cin>>x_check;
    y_check=a0+(a1*x_check);
    printf("Y= ");
    cout<<y_check<<endl;
    for(i=0;i<n;i++)
    {
        if(x_check==x[i])
        {
            printf("Absolute error: ");
            cout<<abs(y_check-y[i]);
            break;
        }
    }
    printf("\n\n");
}

void non_linear_curve(void)
{
    int i,n;
    double s_x=0;
    double s_y=0;
    double s_x2=0;
    double s_x3=0;
    double s_x4=0;
    double s_x2y=0;
    double s_xy=0;
    double d,dC,dA,dB,a0,a1,a2;
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
    a0=dA/d;
    a1=dB/d;
    a2=dC/d;

    cout<<"a0="<<a0<<"\na1="<<a1<<"\na2="<<a2<<endl;

    printf("Enter a value of x: ");
    cin>>x_check;
    y_check=a0+(a1*x_check)+(a2*x_check*x_check);
    printf("Y= ");
    cout<<y_check<<endl;
    for(i=0;i<n;i++)
    {
        if(x_check==x[i])
        {
            printf("Absolute error: ");
            cout<<abs(y[i]-y_check);
            break;
        }
    }
    printf("\n\n");
}

void exponential_curve(void)
{
    int n,i;
    double s_x=0;
    double s_y=0;
    double s_x2=0;
    double s_xy=0;
    double a0,a1;
    double a,b;
    double x_check,y_check;

    printf("Enter the number of inputs: ");
    cin>>n;
    double x[n];
    double y[n];
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

    printf("Enter a value of x: ");
    cin>>x_check;
    y_check=a*exp(b*x_check);
    printf("Y= ");
    cout<<y_check<<endl;
    for(i=0;i<n;i++)
    {
        if(x_check==x[i])
        {
            printf("Absolute error: ");
            cout<<abs(y_check-y[i]);
            break;
        }
    }
    printf("\n\n");
}

int main(void)
{
    int checker;

    while(1)
    {
        printf("1. Linear curve fitting\n2. Non-linear curve fitting\n3. Exponential curve fitting\n0. Exit\n   Enter your choice: ");
        cin>>checker;

        switch(checker)
        {
        case 0:
            return 0;

        case 1:
            linear_curve();
            break;

        case 2:
            non_linear_curve();
            break;

        case 3:
            exponential_curve();
            break;

        default:
            printf("Wrong Choice...\n\n");
        }
    }
}
