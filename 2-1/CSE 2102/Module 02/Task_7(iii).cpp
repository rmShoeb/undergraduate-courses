#include<iostream>
#include<cstdio>
using namespace std;

int main(void)
{
    int l,u;
    int sum=0;

    cin>>l>>u;

    while(l<=u)
    {
        sum+=(2*l);
        l++;
    }

    cout<<sum<<endl;
}
