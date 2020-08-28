#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
using namespace std;

int main(void)
{
    int i,k,n;
    int j=1;
    double h,sum1,sum2;
    double x_check;
    double x[10];
    double y[10];
    double d_y[10],d2_y[10],d3_y[10],d4_y[10],d5_y[10],d6_y[10];

    printf("Enter the length of your data: ");
    cin>>n;
    printf("Enter the values:\n x | y\n");
    for(i=0;i<n;i++)
        cin>>x[i]>>y[i];

    h=x[1]-x[0];
    printf("Forward difference table\n");
    printf("\ndy\n");
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
    j++;
    printf("\nd4_y\n");
    for(i=0;i<n-j;i++)
    {
        d4_y[i]=d3_y[i+1]-d3_y[i];
        cout<<d4_y[i];
        printf("\n");
    }
    j++;
    printf("\nd5_y\n");
    for(i=0;i<n-j;i++)
    {
        d5_y[i]=d4_y[i+1]-d4_y[i];
        cout<<d5_y[i];
        printf("\n");
    }
    j++;
    printf("\nd6_y\n");
    for(i=0;i<n-j;i++)
    {
        d6_y[i]=d5_y[i+1]-d5_y[i];
        cout<<d6_y[i];
        printf("\n");
    }

    printf("Enter a value of x to check: ");
    cin>>x_check;

    for(i=0;i<n;i++)
    {
        if(x_check==x[i])
            break;
    }
    k=i;
    sum1=(1/h)*(d_y[k]-((d2_y[k])/2)+((d3_y[k])/3)-((d4_y[k])/4)+((d5_y[k])/5));
    sum2=(1/(h*h))*(d2_y[k]-d3_y[k]+(.9167*(d4_y[k]))-(.833*(d5_y[k])));
    printf("dy/dx: ");
    cout<<sum1<<endl;
    printf("d2y/dx2: ");
    cout<<sum2<<endl;
    return 0;
}
