#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
using namespace std;

int main(void)
{
    long long int l,u,a,r;
    long long int sum=0;

    cin>>l>>u>>a>>r;

    for(;l<=u;l++)
    {
        sum+=(a+pow(r,l));
    }

    cout<<sum<<endl;
}
