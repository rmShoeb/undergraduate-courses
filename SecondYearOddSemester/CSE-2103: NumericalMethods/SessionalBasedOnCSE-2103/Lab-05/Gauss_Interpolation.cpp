#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
using namespace std;

int main(void)
{
    int n,i,j,checker;
    double ax[200],ay[200],diff[200][200];
    double x,p,h,nr,dr,y=0,y1,y2,y3,y4,y5,y6;

    printf("Enter the number of inputs: ");
    cin>>n;
    printf("Enter the points:/n  x  |  y\n");
    for(i=0;i<n;i++)
        cin>>ax[i]>>ay[i];
    h=ax[1]-ax[0];
    for(i=0;i<n-1;i++)
        diff[i][1]=ay[i+1]-ay[i];
    for(j=2;j<=4;j++)
    {
        for(i=0;i<n-j;i++)
            diff[i][j]=diff[i+1][j-1]-diff[i][j-1];
    }
    while(1)
    {
        printf("1. Forward formula\n2. Backward formula\n0. Exit\n   Enter your choice: ");
        cin>>checker;
        switch(checker)
        {
        case 0:
            return 0;

        case 1:
            printf("Enter the value of x: ");
            cin>>x;
            for(i=0;ax[i]<x;i++);
            p=(x-ax[i])/h;
            y1=p*diff[i][1];
            y2=p*(p-1)*diff[i-1][2]/2;
            y3=(p+1)*p*(p-1)*diff[i-2][3]/6;
            y4=(p+1)*p*(p-1)*(p-2)*diff[i-3][4]/24;
            y=ay[i]+y1+y2+y3+y4;

            cout<<"Desired value of y:"<<y<<endl;
            break;

        case 2:
            printf("Enter the value of x: ");
            cin>>x;
            for(i=0;ax[i]<x;i++);
            p=(x-ax[i])/h;
            y1=p*diff[i-1][1];
            y2=p*(p+1)*diff[i-1][2]/2;
            y3=(p+1)*p*(p-1)*diff[i-2][3]/6;
            y4=(p+1)*p*(p-1)*(p+2)*diff[i-3][4]/24;
            y=ay[i]+y1+y2+y3+y4;

            cout<<"Desired value of y:"<<y<<endl;
            break;

        default:
            printf("Wrong input...\n");
        }
    }
}
