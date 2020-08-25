#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
using namespace std;

int main(void)
{
    long long int a,d,l,u;
    long long int sum=0;

    cin>>l>>u>>a>>d;
    for(;l<=u;l++)
    {
        sum+=(a+l*d);
    }

    cout<<sum<<endl;
}
