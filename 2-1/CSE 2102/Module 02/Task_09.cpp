#include<iostream>
#include<cstdio>
using namespace std;
///using the Gregory_Leibniz Series
int main(void)
{
    int i;
    double pi=1;

    for(i=2;;i++)
    {
        if(1/(double)(2*i-1)<0.00001)
            break;
        else if(i%2==0)
        {
            printf("-1/%d",(2*i-1));
            pi-=(1/(double)(2*i-1));
        }
        else
        {
            printf("+1/%d",(2*i-1));
            pi+=(1/(double)(2*i-1));
        }
    }

    printf("=");
    cout<<(4*pi)<<endl;
}
