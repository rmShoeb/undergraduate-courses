#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cmath>
#include<vector>
using namespace std;

int n;
int i;

void for_pol(double x[], double y[], double x_cal)
{
    vector<double>d_y;
    double temp;
    double h;
    double p;
    int counter;
    int j=0;

    h=x[1]-x[0];
    p=(x_cal-x[0])/h;
    for(i=1;i<n;i++)
    {
        temp=y[i]-y[i-1];
        d_y.push_back(temp);
        printf("dy%d = %d\t",j,(int)temp);
        j++;
    }
    printf("\n");
    counter=n-1;
    while(counter)
    {
        for(i=0;i<counter-1;i++)
        {
            temp=d_y[j+1]-d_y[j];
            d_y.push_back(temp);
            printf("d^%dy%d = %d\t",counter,i,(int)temp);
            j++;
        }
        printf("\n");
        counter--;
    }
}
void back_pol(double x[], double y[], double x_cal)
{
    vector<double>d_y;
    double temp;
    double h;
    double p;
    int counter;

    h=x[1]-x[0];
    p=(x_cal-x[0])/h;
    for(i=1;i<n;i++)
    {
        temp=y[i]-y[i-1];
        d_y.push_back(temp);
    }
}


int main(void)
{
    cout<<"Enter your input size: ";
    cin>>n;
    double x[n];
    double y[n];
    int ck;
    double x_cal;

    cout<<"Enter values for x: ";
    for(i=0;i<n;i++)
        cin>>x[i];
    cout<<"Enter values for y: ";
    for(i=0;i<n;i++)
        cin>>y[i];
    cout<<"Enter the value of x to find corresponding value of y: ";
    cin>>x_cal;

    printf("1. Newton's Forward Difference Interpolation\n2. Newton's Backward Difference Interpolation\n");
    printf("   Enter your choice: ");
    cin>>ck;

    switch(ck)
    {
    case 1:
        for_pol(x,y,x_cal);
        break;

    case 2:
        back_pol(x,y,x_cal);
        break;

    default:
        printf("Wrong choice...\n");
    }
}
