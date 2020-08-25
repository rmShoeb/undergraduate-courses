#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cstdint>
#include<algorithm>
using namespace std;

int fact(int x)
{
    if(x>1)
        return x*fact(x-1);
    else
        return 1;
}



int main(void)
{
    int n,r,i;
    int permu=1;
    int comb=1;
    cout<<"Enter n: ";
    cin>>n;
    cout<<"Enter r: ";
    cin>>r;

    for(i=0;i<r;i++)
        permu*=n;
    cout<<"r-permutation="<<permu<<endl;

    i=n;
    n=n+r-1;
    while(i<=n)
    {
        comb*=i;
        i++;
    }
    comb/=fact(r);
    cout<<"r-combination="<<comb<<endl;
}
