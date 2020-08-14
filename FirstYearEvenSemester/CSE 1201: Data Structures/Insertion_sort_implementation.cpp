/**
    editor_rmShoeb
    stated_at_2052_1/7/2018
    finished_at_2108_1/7/2018
    modified_at_2156_1/7/2018
**/
#include<iostream>
#include<cstdio>
#include<cstdlib>
#define n 10
using namespace std;

int main(void)
{
    int arr[n];
    int i,k,temp;

    for(i=0;i<n;i++)
        cin>>arr[i];

    for(i=1;i<n;i++)
    {
        temp=arr[i];
        k=i;
        while(k>0&&arr[k-1]>temp)
        {
            arr[k]=arr[k-1];
            k--;
        }
        arr[k]=temp;
    }

    for(i=0;i<n;i++)
        cout<<arr[i]<<ends;
    cout<<endl;
}
