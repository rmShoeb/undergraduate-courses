#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<algorithm>
using namespace std;

double a,b,c,d;

double func_val(double x)
{
    return (a*x*x*x+b*x*x+c*x+d);
}

int main(void)
{
    double x,y;
    double temp;
    double avg;
    double f_x,f_y;
    int i;

    cout<<"ax3+bx2+cx+d"<<endl;
    cout<<"a=";
    cin>>a;
    cout<<"b=";
    cin>>b;
    cout<<"c=";
    cin>>c;
    cout<<"d=";
    cin>>d;

    ///finding_positive_value
    while(1)
    {
        cin>>x;
        temp=func_val(x);
        if(temp<0)
            cout<<"Try again"<<endl;
        else
        {
            f_x=temp;
            break;
        }
    }

    ///finding_negative_value
    while(1)
    {
        cin>>y;
        temp=func_val(y);
        if(temp<0)
        {
            f_x=temp;
            break;
        }
        else
            cout<<"Try again."<<endl;
    }

    printf("  n  |      x     |      y     |   average  |     f(x)    |    f(y)    \n");
    printf("-------------------------------------------------------------------------------------\n");
    for(i=1;;i++)
    {
        avg=(x+y)/2;
        printf("%5d|%5.10f|%5.10f|%5.10f|%5.10f|%5.10f\n",i,x,y,avg,func_val(x),func_val(y));
        printf("-------------------------------------------------------------------------------------\n");
        //break;
        if(func_val(avg)<0.0001)
            y=avg;
        else if(func_val(avg)>0.0001)
            x=avg;
        else
            break;
    }
    printf("Answer: %f\n",avg);
}
