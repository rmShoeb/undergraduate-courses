#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
using namespace std;

int main(void)
{
    double a,a1, x[100],y[100],d[100],d2[100],d3[100],d4[100],xa,p,h;
    int i,j,k,n,m,c;
    printf("Enter the number of points:");
    cin>>n;
    cout<<"Enter the data point:"<<endl;
    cout<<"x | y=f(x)"<<endl;
    for(i=0;i<n;i++)
        cin>>x[i]>>y[i];
    while(1)
    {
        printf("1.Forward interpolation\n2.Backward interpolation\n3.Exit\n");
        printf("Enter your choice: ");
        cin>>c;
        switch(c)
        {
            case 1:
            {
                cout<<"\nEnter required point:";
                cin>>xa;
                h=(x[1]-x[0]);
                p=(xa-x[0])/h;
                for(i=0; i<n-1; i++)
                {
                    d[i]=y[i+1]-y[i];
                    printf("d[%d] = %d\n",i,(int)d[i]);
                }
                printf("\n");
                for(i=0; i<n-2; i++)
                {
                    d2[i]=d[i+1]-d[i];
                    printf("d2[%d] = %d\n",i,(int)d2[i]);
                }
                printf("\n");
                for(i=0; i<n-3; i++)
                {
                    d3[i]=d2[i+1]-d2[i];
                    printf("d3[%d] = %d\n",i,(int)d3[i]);
                }
                printf("\n");
                for(i=0; i<n-4; i++)
                {
                    d4[i]=d3[i+1]-d3[i];
                    printf("d4[%d] = %d\n",i,(int)d4[i]);
                }
                a= y[0]+p*d[0]+((p*(p-1))*d2[0])/2+((p*(p-1)*(p-2))*d3[0])/6+((p*(p-1)*(p-2)*(p-3))*d4[0])/24;
                printf("Value at given point is %d\n\n",(int)a);
            }
            break;
            case 2:
            {
                cout<<"\nEnter required point:";
                cin>>xa;
                h=(x[1]-x[0]);
                p=(xa-x[n-1])/h;
                for(i=0; i<n-1; i++)
                {
                    d[i]=y[i+1]-y[i];
                    printf("d[%d] = %d\n",i,(int)d[i]);
                }
                printf("\n");
                for(i=0; i<n-2; i++)
                {
                    d2[i]=d[i+1]-d[i];
                    printf("d2[%d] = %d\n",i,(int)d2[i]);
                }
                printf("\n");
                for(i=0; i<n-3; i++)
                {
                    d3[i]=d2[i+1]-d2[i];
                    printf("d3[%d] = %d\n",i,(int)d3[i]);
                }
                printf("\n");
                for(i=0; i<n-4; i++)
                {
                    d4[i]=d3[i+1]-d3[i];
                    printf("d4[%d] = %d\n",i,(int)d4[i]);
                }
                a1=y[n-1]+p*d[n-2]+((p*(p+1))*d2[n-3])/2+((p*(p+1)*(p+2))*d3[n-4])/6+((p*(p+1)*(p+2)*(p+3))*d4[n-5])/24;
                printf("Value at given point is %d\n\n",(int)a);
            }
            break;
            case 3:
                return 0;
            default:
                printf("Wrong input...\n");
        }
    }
}
