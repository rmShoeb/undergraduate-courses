#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
using namespace std;

int n;
int i,j;

bool A_A_p(int a[],int b[])
{
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if((a[i]*a[i])!=b[j])
                return false;
        }
    }
    return true;
}

bool A_E_p(int a[], int b[])
{
    int temp=0;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if((a[i]*a[i])==b[j])
            {
                temp++;
                break;
            }
        }
    }
    if(temp==n)
        return true;
    else
        return false;
}

bool E_A_p(int a[],int b[])
{
    int temp;
    for(i=0;i<n;i++)
    {
        temp=0;
        for(j=0;j<n;j++)
        {
            if(a[i]*a[i]!=b[j])
                break;
            else
                ++temp;
        }
        if(temp==n)
            return true;
    }
    return false;
}

bool E_E_p(int a[],int b[])
{
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(a[i]*a[i]==b[j])
                return true;
        }
    }
    return false;
}

int main(void)
{
    cout<<"Enter size of your input: ";
    cin>>n;
    int a[n];
    int b[n];

    cout<<"Enter values for x: ";
    for(i=0;i<n;i++)
        cin>>a[i];

    cout<<"Enter values for y: ";
    for(i=0;i<n;i++)
        cin>>b[i];

    cout<<"A,A,p(x,y)->";
    if(A_A_p(a,b))
        cout<<"True"<<endl;
    else
        cout<<"False"<<endl;

    cout<<"A,E,p(x,y)->";
    if(A_E_p(a,b))
        cout<<"True"<<endl;
    else
        cout<<"False"<<endl;

    cout<<"E,A,p(x,y)->";
    if(E_A_p(a,b))
        cout<<"True"<<endl;
    else
        cout<<"False"<<endl;

    cout<<"E,E,p(x,y)->";
    if(E_E_p(a,b))
        cout<<"True"<<endl;
    else
        cout<<"False"<<endl;
}
