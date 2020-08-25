#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstdint>
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
    int permu,comb;
    cout<<"Enter n: ";
    cin>>n;
    cout<<"Enter r: ";
    cin>>r;

    cout<<"r-permutation=";
    permu=1;
    for(i=(n-r+1);i<=n;i++)
        permu*=i;
    cout<<permu<<endl;

    cout<<"r-combination=";
    comb=(permu/fact(r));
    cout<<comb<<endl;
}
