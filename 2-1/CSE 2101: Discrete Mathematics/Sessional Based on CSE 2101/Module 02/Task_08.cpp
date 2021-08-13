#include<iostream>
#include<cstdio>
using namespace std;

int main(void)
{
    double sum=0;
    int i;

    for(i=1;;i*=2)
    {
        if((1/(double)i)<0.000000001)
            break;
        else
        {
            sum+=(1/(double)i);
            printf("1/%d+",i);
        }
    }
    printf("1/%d=",i);
    sum+=(1/(double)i);
    cout<<sum<<endl;
}
