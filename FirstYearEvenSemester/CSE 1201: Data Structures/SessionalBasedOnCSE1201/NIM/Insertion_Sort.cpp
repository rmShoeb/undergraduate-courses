///there is a huge problem in the code. it's sorting the file, but skipping most of the elements and filling those gaps with the elements it's working with.
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
    sorted=fopen("insertion_sort.txt","w");
    int arr[10000];
    int i,j;
    for(i=0;i<10000;i++)
        fscanf(fp,"%d",&arr[i]);
    double start=clock();
    for(i=1;i<10000;i++)
    {
        j=i-1;
        while(j>=0&&arr[i]<arr[j])
        {
            arr[j+1]=arr[j];
            j-=1;
        }
        arr[j+1]=arr[i];
    }
    double stop=clock();
    for(i=0;i<10000;i++)
        fprintf(sorted,"%d ",arr[i]);
    fclose(fp);
    fclose(sorted);
    cout<<(stop-start)/(double)CLOCKS_PER_SEC*1000<<endl;
}
