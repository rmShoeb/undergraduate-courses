#include<stdio.h>
#include<stdlib.h>
#include<time.h>



int main(void)
{
    int arr[20000];
    int i;
    srand(time(0));
    for(i=0;i<20000;i++)
    {
        arr[i]=rand()%1001;
    }

    double start=clock();
    int key,j;
    for (i=1;i<20000;i++)
    {
       key=arr[i];
       j=i-1;

       while(j>=0&&arr[j]>key)
       {
           arr[j+1]=arr[j];
           j=j-1;
       }
       arr[j+1]=key;
    }
    double stop=clock();

    printf("%lf\n",(stop-start)/CLOCKS_PER_SEC*1000);

    return 0;
}
