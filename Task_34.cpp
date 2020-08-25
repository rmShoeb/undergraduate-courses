#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;

int main(void)
{
    int m,k,n;
    int i,j,p;
    int temp;

    printf("Enter values for dimension of matrix:\n m | k | n\n");
    cin>>m>>k>>n;
    int a[m][k];
    int b[k][n];
    int ab[m][n];

    printf("Enter matrix A:\n");
    for(i=0;i<m;i++)
    {
        for(j=0;j<k;j++)
            cin>>a[i][j];
    }

    printf("Enter matrix B:\n");
    for(i=0;i<k;i++)
    {
        for(j=0;j<n;j++)
            cin>>b[i][j];
    }

    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            temp=0;
            for(p=0;p<k;p++)
            {
                temp+=(a[i][p]*b[p][j]);
            }
            ab[i][j]=temp;
        }
    }

    printf("The matrix AB will be:\n");
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            cout<<ab[i][j];
            printf(" ");
        }
        cout<<endl;
    }
}
