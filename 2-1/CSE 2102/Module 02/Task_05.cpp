#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<algorithm>
using namespace std;

bool func_1(int n)
{
    vector<int>range;
    int i;
    int temp;

    for(i=1;i<=n;i++)
    {
        temp=i*i;
        range.push_back(temp);
    }

    sort(range.begin(), range.end());

    for(i=0;i<n;i++)
    {
        if(range[i]!=(i+1))
            return false;
    }
    return true;
}

bool func_2(int n)
{
    vector<int>range;
    int i;
    int temp;

    for(i=1;i<=n;i++)
    {
        temp=i+1;
        range.push_back(temp);
    }

    sort(range.begin(), range.end());

    for(i=0;i<n;i++)
    {
        if(range[i]!=(i+1))
            return false;
    }
    return true;
}

bool func_3(int n)
{
    vector<int>range;
    int i;
    int temp;

    for(i=1;i<=n;i++)
    {
        temp=i*i*i+i*i+i+1;
        range.push_back(temp);
    }

    sort(range.begin(), range.end());

    for(i=0;i<n;i++)
    {
        if(range[i]!=(i+1))
            return false;
    }
    return true;
}


int main(void)
{
    int n;
    printf("Enter the last element of the domain: ");
    cin>>n;

    printf("Function-1 is ");
    if(!func_1(n))
        printf("not ");
    printf("onto.\n");

    printf("Function-2 is ");
    if(!func_2(n))
        printf("not ");
    printf("onto.\n");

    printf("Function-3 is ");
    if(!func_3(n))
        printf("not ");
    printf("onto.\n");
}
