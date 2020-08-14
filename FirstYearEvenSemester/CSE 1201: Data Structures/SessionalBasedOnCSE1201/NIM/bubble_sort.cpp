#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>
using namespace std;
int main(void)
{
    FILE *fp;
    FILE *sorted;
    fp=fopen("file.txt","r");              ///complexity 1
    sorted=fopen("bubble sort.txt","w");   ///complexity 1
    int i,j,temp;
    int arr[1000];
    double start=clock();                  ///complexity 1
    for(i=0;i<1000;i++)                    ///complexity 2n+2
        fscanf(fp,"%d",&arr[i]);           ///complexity 1
    for(i=0;i<1000;i++)                    ///complexity 4*2n(2n+2)+n+2=16n2+17n+2
    {
        for(j=i;j<1000;j++)                ///complexity 4(2n+2)=8n+8
        {
            if(arr[i]>arr[j])              ///complexity 1
            {
                temp=arr[i];               ///complexity 1
                arr[i]=arr[j];             ///complexity 1
                arr[j]=temp;               ///complexity 1
            }
        }
    }
    for(i=0;i<1000;i++)                    ///complexity 2n+2
    {
        fprintf(sorted,"%d ",arr[i]);      ///complexity 1
    }
    double stop=clock();                   ///complexity 1
    cout<<(stop-start)/CLOCKS_PER_SEC*1000<<endl;              ///complexity 1
    fclose(fp);
    fclose(sorted);
    return 0;                              ///total complexity 16n2+21n+10
}                                          ///complexity of the program n2
