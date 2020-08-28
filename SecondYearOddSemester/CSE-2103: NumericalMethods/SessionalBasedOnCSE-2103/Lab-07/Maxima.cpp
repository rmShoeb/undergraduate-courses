#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<cstring>
using namespace std;

int main(void)
{
    int i,n,c,a;
    int j=1;
    double b;
    double x[10];
    double y[10];
    double d_y[10],d2_y[10],d3_y[10],d4_y[10];
    double minima;
    double maxima;
    double h,p,p1;
    double xx;

    printf("Enter the length of your data: ");
    cin>>n;
    printf("Enter the values:\n x | y\n");
    for(i=0;i<n;i++)
        cin>>x[i]>>y[i];

    h=x[1]-x[0];
    printf("\nDifference table\n");
    printf("dy\n");
    for(i=0;i<n-j;i++)
    {
        d_y[i]=y[i+1]-y[i];
        cout<<d_y[i];
        printf("\n");
    }
    j++;
    printf("\nd2_y\n");
    for(i=0;i<n-j;i++)
    {
        d2_y[i]=d_y[i+1]-d_y[i];
        cout<<d2_y[i];
        printf("\n");
    }
    j++;
    printf("\nd3_y\n");
    for(i=0;i<n-j;i++)
    {
        d3_y[i]=d2_y[i+1]-d2_y[i];
        cout<<d3_y[i];
        printf("\n");
    }

    p=0.5-(d_y[0]/d2_y[0]);
    xx=x[0]+p*h;
    printf("Maximum value of the tabulated function will be found for the value of x= ");
    cout<<xx<<endl;
    maxima=y[0]+p*d_y[0]+(p*(p-1)*d2_y[0]*0.5)+((p*(p-1)*(p-2)*d3_y[0])/6);
    printf("And the maximum value will be: ");
    cout<<maxima<<endl;
}
