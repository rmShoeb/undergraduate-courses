/**
    editor_rmShoeb
    started_at_1518_1/7/2018
    finished_at_1539_1/7/2018
    modified_at_1905_1/7/2018_now_it_works____correctly
    and i still don't know what the heck i have written____whatever it is__it works fine__that's enough for me
**/
#include<iostream>
#include<cstdio>
#include<cstdlib>
#define n 20
using namespace std;

void merge_list(int l[], int l_size, int r[], int r_size, int arr[])
{
    int i,j,k;
    i=j=k=0;

    while(i<l_size&&j<r_size)
    {
        if(l[i]<r[j])
        {
            arr[k]=l[i];
            i++;
        }
        else
        {
            arr[k]=r[j];
            j++;
        }
        k++;
    }
    while(i<l_size)
    {
        arr[k]=l[i];
        i++;
        k++;
    }
    while(j<r_size)
    {
        arr[k]=r[j];
        j++;
        k++;
    }
}

void merge_sort(int arr[], int arr_size)
{
    int mid;
    mid=arr_size/2;
    int l[mid];
    int r[arr_size-mid];
    int i,j;

    if(arr_size>1)
    {
        for(i=0,j=0;i<mid;i++,j++)
            l[i]=arr[j];
        for(i=0;i<(arr_size-mid);i++,j++)
            r[i]=arr[j];

        merge_sort(l,mid);
        merge_sort(r,arr_size-mid);
        merge_list(l,mid,r,arr_size-mid,arr);
    }
}


int main(void)
{
    int arr[n];
    int i;

    for(i=0;i<n;i++)
        cin>>arr[i];

    merge_sort(arr, n);

    for(i=0;i<n;i++)
        cout<<arr[i]<<ends;
    cout<<endl;
}
