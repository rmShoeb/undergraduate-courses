#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<ctime>
using namespace std;
int main(void)
{
    FILE *fp;
    FILE *sorted;
    fp=fopen("file.txt","r");
    sorted=fopen("selection_sort.txt","w");
    int arr[10000];
    int i,j,temp,k;
    for(i=0;i<10000;i++)
        fscanf(fp,"%d",&arr[i]);
    double start=clock();
    for(i=0;i<10000;i++)
    {
        k=i;
        for(j=i+1;j<10000;j++)
        {
            if(arr[k]>arr[j])
                k=j;
        }
        temp=arr[k];
        arr[k]=arr[i];
        arr[i]=temp;
    }
    double stop=clock();
    for(i=0;i<10000;i++)
        fprintf(sorted,"%d ",arr[i]);
    fclose(fp);
    fclose(sorted);
    cout<<(stop-start)/(double)CLOCKS_PER_SEC*1000<<endl;
}
