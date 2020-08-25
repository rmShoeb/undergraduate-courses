///pre-processor_directives
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<algorithm>
using namespace std;

///global_variables
int n;
int i;

///user_defined functions

void bitwise_or(bool p[],bool q[])
{
    for(i=0;i<n;i++)
        cout<<(p[i]||q[i]);
    cout<<endl;
}

void bitwise_and(bool p[],bool q[])
{
    for(i=0;i<n;i++)
        cout<<(p[i]&&q[i]);
    cout<<endl;
}

void bitwise_x_or(bool p[],bool q[])
{
    for(i=0;i<n;i++)
        cout<<(((!p[i])&&q[i])||(p[i]&&(!q[i])));
    cout<<endl;
}

int main(void)
{

    cout<<"Enter string length: ";
    cin>>n;
    char P[n];
    char Q[n];
    bool p[n];
    bool q[n];

    ///input section
    cout<<"Enter p: ";
    cin>>P;
    cout<<"Enter q: ";
    cin>>Q;

    ///processing
    for(i=0;i<n;i++)
    {
        if(P[i]=='1')
            p[i]=1;
        else
            p[i]=0;
    }

    for(i=0;i<n;i++)
    {
        if(Q[i]=='1')
            q[i]=1;
        else
            q[i]=0;
    }

    cout<<"Showing bitwise OR\n";
    bitwise_or(p,q);
    cout<<"Showing bitwise AND\n";
    bitwise_and(p,q);
    cout<<"Showing bitwise X-OR\n";
    bitwise_x_or(p,q);
}
