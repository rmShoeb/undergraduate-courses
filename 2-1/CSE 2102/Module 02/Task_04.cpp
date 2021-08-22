#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<vector>
using namespace std;

bool func_1(int n)
{
    vector<int>temp1;
    int temp2;
    int i,j;

    temp2=1;
    temp1.push_back(temp2);
    for(i=2;i<=n;i++)
    {
        temp2=i*i;
        for(j=0;j<i-1;j++)
        {
            if(temp2==temp1[j])
                return false;
        }
        temp1.push_back(temp2);
    }
    return true;
}

bool func_2(int n)
{
    vector<int>temp1;
    int temp2;
    int i,j;

    temp2=2;
    temp1.push_back(temp2);
    for(i=2;i<n;i++)
    {
        temp2=i+1;
        for(j=0;j<i-1;j++)
        {
            if(temp2==temp1[j])
                return false;
        }
        temp1.push_back(temp2);
    }
    return true;
}

bool func_3(int n)
{
    vector<int>temp1;
    int temp2;
    int i,j;

    temp2=4;
    temp1.push_back(temp2);
    for(i=2;i<n;i++)
    {
        temp2=i*i*i+i*i+i+1;
        for(j=0;j<i-1;j++)
        {
            if(temp2==temp1[j])
                return false;
        }
        temp1.push_back(temp2);
    }
    return true;
}

int main(void)
{
    int n;

    printf("Enter the last element of the domain: ");
    cin>>n;

    printf("\nFunction-1 is ");
    if(!func_1(n))
        printf("not ");
    printf("one-to-one.\n");

    printf("\nFunction-2 is ");
    if(!func_2(n))
        printf("not ");
    printf("one-to-one.\n");

    printf("\nFunction-3 is ");
    if(!func_3(n))
        printf("not ");
    printf("one-to-one.\n");
}
