#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
using namespace std;

int main(void)
{
    double x[100];
    double y[100];
    double sum=0;
    double yy,xx;
    int n,i,j;
    int checker;
    double r,s;

    printf("Enter the number of inputs: ");
    cin>>n;
    printf("enter your values:\n");
    printf("  x  |  y\n");
    for(i=0;i<n;i++)
    {
       cin>>x[i];
       cin>>y[i];
    }

    while(1)
    {
        printf("1. To find y\n2. To find x\n0. Exit\n   Enter your choice: ");
        cin>>checker;
        switch(checker)
        {
        case 0:
            return 0;

        case 1:
            printf("Enter the value of x: ");
            cin>>xx;
            for(i=0;i<n;i++)
            {
                 r=1;
                 s=1;
                 for(j=0;j<n;j++)
                 {
                     if(j!=i)
                     {
                         r=r*(xx-x[j]);
                         s=s*(x[i]-x[j]);
                     }
                 }
                 sum+=(r/s)*y[i];
            }
            cout<<"y= "<<sum<<endl;
            sum=0;
            break;

        case 2:
            printf("Enter the value of y: ");
            cin>>yy;
            for(i=0;i<n;i++)
            {
                 r=1;
                 s=1;
                 for(j=0;j<n;j++)
                 {
                     if(j!=i)
                     {
                         r=r*(yy-y[j]);
                         s=s*(y[i]-y[j]);
                     }
                 }
                 sum+=(r/s)*x[i];
            }
            cout<<"X= "<<sum<<endl;
            sum=0;
            break;

        default:
            printf("Wrong choice...\n");
        }
    }
}
