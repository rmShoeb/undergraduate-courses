#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<vector>
using namespace std;

int main(void)
{
    double a[100]={0};
    double temp;
    vector<double>b;
    int i,n;
    int iter=1;

    a[1]=(13/12.0);
    a[2]=(-3/8.0);
    a[3]=(1/24.0);

    b.push_back(0);
    b.push_back(1);
    temp=a[1]*b[1];
    b.push_back(temp);

    printf("Solution for\n\tx3-9x2+26x-24=0\n\n");
    n=1;
    printf("n|      a      |      b     |  bn-1/bn\n");
    printf("--------------------------------------\n");
    printf("%d|%3.10f|%3.10f|  ----  \n",iter++,a[n],b[n]);
    printf("--------------------------------------\n");
    n++;
    printf("%d|%3.10f|%3.10f|%3.10f\n",iter++,a[n],b[n],b[n-1]/b[n]);
    printf("--------------------------------------\n");
    n++;

    while(1)
    {
        b.push_back(0);
        for(i=1;i<n;i++)
            b[n]+=(a[i]*b[n-i]);

        printf("%d|%3.10f|%3.10f|%3.10f\n",iter++,a[n],b[n],b[n-1]/b[n]);
        printf("--------------------------------------\n");

        if(abs((b[n-2]/b[n-1])-(b[n-1]/b[n]))<=0.00001)
            break;
        else
            n++;
    }

    printf("\nAnswer: ");
    cout<<(b[n-1]/b[n])<<endl;
}
