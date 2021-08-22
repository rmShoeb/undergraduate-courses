#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;

int n;

bool A_A_p(int a[],int b[])
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(a[i]*a[i]!=b[j])
                return false;
        }
    }
    return true;
}

bool A_E_p(int a[],int b[])
{
    int temp;
    for(int i=0;i<n;i++)
    {
        temp=2;
        for(int j=0;j<n;j++)
        {
            if(a[i]*a[i]==b[j])
            {
                temp=1;
                break;
            }
        }
        if(temp==2)
            return false;
    }
    return true;
}

bool E_A_p(int a[],int b[])
{
    int temp;
    for(int i=0;i<n;i++)
    {
        temp=0;
        for(int j=0;j<n;j++)
        {
            if(a[i]*a[i]==b[j])
                temp++;
        }
        if(temp==n)
            return true;
    }
    return false;
}

bool E_E_p(int a[],int b[])
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;i<n;i++)
        {
            if(a[i]*a[i]==b[j])
                return true;
        }
    }
    return false;
}

int main(void)
{
    cout<<"Enter your input size: ";
    cin>>n;

    int a[n];
    int b[n];
    int i;

    cout<<"Enter data for set A: ";
    for(i=0;i<n;i++)
        cin>>a[i];

    cout<<"Enter data for set B: ";
    for(i=0;i<n;i++)
        cin>>b[i];

    cout<<A_A_p(a,b)<<endl;
    cout<<A_E_p(a,b)<<endl;
    cout<<E_A_p(a,b)<<endl;
    cout<<E_E_p(a,b)<<endl;
}
